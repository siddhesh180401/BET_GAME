// "Simple betting game"
// "Jack Queen King - computer shuffles these cards"
// Player has to guess the position of queen.
// if wins, he takes 3*bet
// if he losses, he looses the bet amount
// player has $100 initially

#include <bits/stdc++.h>
using namespace std;

int cash = 100;

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void randomize(char arr[], int n)
{
    // Use a different seed value so that
    // we don't get same result each time
    // we run this program
    srand(time(NULL));

    // Start from the last element and swap
    // one by one. We don't need to run for
    // the first element that's why i > 0
    for (int i = n - 1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i + 1);

        // Swap arr[i] with the element
        // at random index
        swap(&arr[i], &arr[j]);
    }
}

void playgame(int bet)
{
    char c[4] = {'A', 'K', 'Q', 'J'};
    printf("Shuffling...\n");
    srand(time(NULL));

    randomize(c, 4);

    int PlayerGuess;
    printf("what's the position of queen 1, 2, 3 or 4 ? ");
    scanf("%d", &PlayerGuess);
    if (c[PlayerGuess - 1] == 'Q')
    {
        cash += 3 * bet;
        printf("You Win ! Result = \"%c %c %c %c\" Total cash = $%d\n", c[0], c[1], c[2], c[3], cash);
        cout << endl;
        cout << setw(45) << "Congratulation\n";
    }
    else
    {
        cash -= bet;
        printf("You Loose bitch! Result = \"%c %c %c %c\" Total cash = $%d\n", c[0], c[1], c[2], c[3], cash);
        cout << setw(45) << "Better luck next time\n";
    }
    cout << "--------------------------------------------------------------------\n";
}

int main()
{
    cout << "--------------------------------------------------------------------\n";
    cout << setw(45) << "WELCOME PLAY AND WIN\n";
    int bet;

    printf("Total cash = %d\n", cash);

    while (cash > 0)
    {
        printf("What's your bet? $");
        scanf("%d", &bet);
        if (bet == 0 || bet > cash)
            break;
        playgame(bet);
    }

    return 0;
}