#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a football team
struct Team {
    char name[50];
    int score;
};

// Function to update the score of a team
void updateScore(struct Team *team) {
    team->score += rand() % 4; // Randomly increase the score by 0-3
}

// Function to display the score of all teams
void displayScores(struct Team *teams, int numTeams) {
    printf("Current Scores:\n");
    for (int i = 0; i < numTeams; i++) {
        printf("%s: %d\n", teams[i].name, teams[i].score);
    }
    printf("\n");
}

int main() {
    // Number of teams
    const int numTeams = 2;

    // Array of teams
    struct Team *teams = (struct Team *)malloc(numTeams * sizeof(struct Team));
    if (teams == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize team names
    strcpy(teams[0].name, "Team A");
    strcpy(teams[1].name, "Team B");

    // Initialize team scores
    for (int i = 0; i < numTeams; i++) {
        teams[i].score = 0;
    }

    // Update scores randomly
    for (int i = 0; i < 5; i++) { // Update scores for 5 rounds
        for (int j = 0; j < numTeams; j++) {
            updateScore(&teams[j]);
        }
    }

    // Display scores
    displayScores(teams, numTeams);

    // Free dynamically allocated memory
    free(teams);

    return 0;
}

