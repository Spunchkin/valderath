#include <ctime>
#include <iostream>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <vector>
class Cat {
public:
  float hunger = 0;

  std::string mood;

  int is_tired = 0;

  std::string hungry_quotes[4] = {"I need to fill my insides!",
                                  "Please feed meow!!", "*stomach gurgle*",
                                  "Could really use a cigarette right meow"};
  std::string neutral_quotes[4] = {
      "Feeling ok ig", "Kinda Bored, gimme food meow",
      "Can't wait till this shit is over",
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
  int fish = 99;
  int cookie = 99;
  int bread = 99;

  // timers

  int fetch_time = std::time(NULL);
  int memory_time = std::time(NULL);

  // updates the modd at the beggining

  valderath.upd_mood();

  // choice of what to do and playing variables

  int choice;

  // playing variable, will be used to quit

  bool playing = true;

  // happiness points, used to buy things

  int happiness = 0;

  // game loop

  while (playing == true) {
    // init the seed to the current time
    srand(std::time(NULL));
    std::string quote;

    // gets current time, so we can calculate how much to  give
    // valderath at the next "turn"

    int current_time = std::time(NULL);
    int currenter_time = current_time;

    // clears screen

    system("clear");

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
    printf("\n \n 1.feed \n 2.buy food \n 3.play \n 4.general shop \n 5.exit "
           "\n choice: ");
    std::cin >> choice;

    // feed logic
    if (choice == 1) {
      system("clear");
      printf(
          "what to feed:\n 1.bread \n 2.cookie \n 3.fish\n 4.exit \n choice: ");
      std::cin >> choice;
      if (choice == 1) {
        if (bread >= 1) {
          valderath.hunger += 2;
          happiness++;
          bread -= 1;
        } else {
          system("clear");
          printf("\n \n !!No bread available to give!! \n \n");
          sleep(1);
          continue;
        };
      } else if (choice == 2) {
        if (cookie >= 1) {
          valderath.hunger += 4;
          happiness += 2;
          cookie -= 1;
          continue;
        } else {
          system("clear");
          printf("\n \n !!No cookies available to give!! \n \n");
          sleep(1);
          continue;
        };
      } else if (choice == 3) {
        if (fish >= 1) {
          valderath.hunger += 16;
          happiness += 4;
          fish -= 1;
        } else {
          system("clear");
          printf("\n \n !!No fish available to give!! \n \n");
          sleep(1);
          continue;
        }
      } else if (choice == 4) {
        continue;
      }
    };

    // shop logic
    if (choice == 2) {
      system("clear");
      printf("shop:\n ");

      printf("1.bread (3 points) \n 2.cookies (5 points) \n 3.fish  (17 "
             "points) \n 4.exit "
             "\n happiness: ");
      printf("%d", happiness);
      printf("\n");

      std::cin >> choice;

      if (choice == 1) {
        if (happiness >= 3) {
          happiness -= 3;
          bread += 1;
          continue;
        } else {
          system("clear");
          printf("\n \n Not enough points \n \n");
          sleep(1);
          continue;
        }
      } else if (choice == 2) {
        if (happiness >= 5) {
          happiness -= 5;
          cookie += 1;
          continue;
        } else {
          system("clear");
          printf("\n \n Not enough points \n \n");
          sleep(1);
          continue;
        }
      } else if (choice == 3) {
        if (happiness >= 17) {
          happiness -= 17;
          fish += 1;
          continue;
        } else {
          system("clear");
          printf("\n \n Not enough points \n \n");
          sleep(1);
          continue;
        }
      } else if (choice == 4) {
        continue;
      }
    };

    if (choice == 3) {
      system("clear");
      // fetch, pet
      printf("What to play: \n1.Fetch\n2.Memory\n3.Exit\nChoice: ");

      std::cin >> choice;

      if (choice == 1) {
        if (currenter_time - fetch_time >= 2) {
          system("clear");
          printf("\n You throw a frisbee...\n");
          sleep(1);
          int caught = rand() % 2;
          if (caught == 1) {
            printf("\n Valderath caught it!!\n");
            sleep(1);
            happiness += 5;
            fetch_time = std::time(NULL);
            continue;
          } else {
            printf("\n Valderath didnt feel like catching\n");
            sleep(1);
            continue;
          }
        } else {
          system("clear");
          printf("\n cooldown\n ");
          sleep(1);
          continue;
        }
      }
      if (choice == 2) {
        if (currenter_time - memory_time >= 5) {
          system("clear");
          printf("\n guess a number between 1 and 5\n choice: ");
          std::cin >> choice;
          int num = rand() % 5;
          sleep(1);
          if (choice == num) {
            memory_time = std::time(NULL);
            happiness += 10;
            printf("\n You got it :) \n");
            sleep(1);
            continue;
          } else {
            printf("\n You didnt get it :( \n");
            sleep(1);
            continue;
          }
        } else {
          system("clear");
          printf("\n cooldown...\n");
          sleep(1);
          continue;
        }
      }
    }

    currenter_time = std::time(NULL);

    if (valderath.hunger <= 0) {
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
