#include <ctime>
#include <iostream>
#include <stdio.h>
#include <string>
#include <unistd.h>
class Cat {
public:
  float hunger = 0;

  std::string mood;

  std::string hungry_quotes[4] = {"I need to fill my insides!",
                                  "Please feed meow!!", "*stomach gurgle*",
                                  "Could really use a cigarette right meow"};
  std::string neutral_quotes[4] = {
      "Feeling ok ig", "Kinda Bored, gimme food meow",
      "Shimmy shimmy yay shimmy yay shimmy ya, drank, swallalala",
      "did you watch the game last night? shit was crazy"};
  std::string satiated_quotes[4] = {"Feeling good!", "*purrs*",
                                    "*munch* *munch* *munch*",
                                    "thanks for the food!!"};
  std::string starving_quotes[4] = {
      "FEED ME NOW!!!!!", "*hiss*", "feed me you fat fuck",
      "if you dont feed me im going after your family"};

  void feed(int foodtype) { hunger += (5 * foodtype); };

  void upd_mood() {
    if (hunger < 20 & hunger > 0) {
      mood = "hungry";
    } else if (hunger <= 0) {
      mood = "starving";
    } else if (hunger >= 50) {
      mood = "satiated";
    } else if (hunger >= 20 & hunger < 50) {
      mood = "neutral";
    };
  }
};

int main() {
  // initializes VALDERATH THE DESTROYER!!!
  Cat valderath;
  valderath.hunger = 20;
  // amount of specific foods the player has
  int fish = 0;
  int cookie = 0;
  int bread = 5;

  // updates the modd at the beggining
  valderath.upd_mood();
  // choice of what to do and playing variables
  int choice;
  bool playing = true;

  // game loop
  while (playing == true) {
    // init the seed to the current time

    srand(std::time(NULL));
    std::string quote;

    // gets current time, so we can calculate how much to  give
    // valderath at the next "turn"

    int current_time = std::time(NULL);

    // clears screen

    system("clear");

    // to make the menu more centered
    printf("\n \n \n");

    // block of code that changes valderath's face
    // depending on his current mood

    if (valderath.mood == "neutral") {
      quote = valderath.neutral_quotes[rand() % 4];
      printf("૮₍  ˶•⤙•˶ ₎ა: ");
      std::cout << quote << "\n";
      printf("Hunger: ");
      printf("%.1f", valderath.hunger);

    } else if (valderath.mood == "starving") {
      quote = valderath.starving_quotes[rand() % 4];
      printf("૮₍ ˃ ⤙ ˂ ₎ა: ");
      std::cout << quote << "\n";
      printf("Hunger: ");
      printf("%.1f", valderath.hunger);

    } else if (valderath.mood == "satiated") {
      quote = valderath.satiated_quotes[rand() % 4];
      printf("૮₍ ˶ᵔ ᵕ ᵔ˶ ₎ა: ");
      std::cout << quote << "\n";
      printf("Hunger: ");
      printf("%.1f", valderath.hunger);

    } else if (valderath.mood == "hungry") {
      quote = valderath.hungry_quotes[rand() % 4];
      printf("(ᴗ _ᴗ) : ");
      std::cout << quote << "\n";
      printf("Hunger: ");
      printf("%.1f", valderath.hunger);
    };

    // prints a new line and takes the input
    // for the players choice for the next turn
    printf(
        "\n \n 1.feed \n 2.buy food \n 3.play \n 4.general shop \n choice: ");
    std::cin >> choice;

    if (choice == 1) {
      system("clear");
      printf("what to feed:\n 1.bread \n 2.cookie \n 3.fish\n choice: ");
      std::cin >> choice;
      if (choice == 1) {
        if (bread >= 1) {
          valderath.hunger += 2;
          bread -= 1;
        } else {
          system("clear");
          printf("\n \n No bread available to give");
          sleep(1);
          continue;
        };
      } else if (choice == 2) {
        if (cookie >= 1) {
          valderath.hunger += 4;
          cookie -= 1;
        } else {
          system("clear");
          printf("\n \n No cookies available to give");
          sleep(1);
          continue;
        };
      } else if (choice == 3) {
        if (fish >= 1) {
          valderath.hunger += 16;
          fish -= 1;
        } else {
          system("clear");
          printf("\n \n No fish available to give");
          sleep(1);
          continue;
        }
      }
    };

    if (valderath.hunger > 0) {
      // calculates the seconds that
      // have past since the last turn
      // so it can upd the hunger
      int currenter_time = std::time(NULL);
      if ((((currenter_time - current_time) * 0.01) - valderath.hunger) < 0) {
        if (currenter_time - current_time >= 1) {
          valderath.hunger -= (currenter_time - current_time) * 0.01;
        }
      } else {
        valderath.hunger -= ((currenter_time - current_time) * 0.01);
      };
      valderath.upd_mood();
    };

    if (valderath.hunger < 0) {
      valderath.hunger = 0;
    };

    continue;
  }
  return 0;
}
