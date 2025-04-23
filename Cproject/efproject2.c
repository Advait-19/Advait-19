#include <stdio.h>
#include <stdlib.h>

// Structure to represent variables for English league matches
struct EPL_League
{
    char h_team[50], a_team[50];
    int goals1, goals2;
    int tshot1, tshot2, ontar1, ontar2;
    char matches[100];
};

// Structure to represent variables for Spanish league matches
struct LaLiga_League
{
    char hm_team[50], awa_team[50];
    int goals3, goals4;
    int tshot3, tshot4, ontar3, ontar4;
    char games[100];
};

int main()
{
    struct EPL_League team1[50];
    struct EPL_League team2[50];
    struct LaLiga_League team3[50];
    struct LaLiga_League team4[50];

    int matno, ch;
    float acc1, acc2;
    int m, n;
    FILE *fp;
    fp = fopen("league.txt","w");
    if(fp=NULL){
      printf("Can not open file");
      return 0;
    }
    printf("For Premier League:\n");
    printf("Enter number of match scores to be updated= ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++)     //Enter details for English League(or Premier League)
    {
        printf("Enter for Match %d:\n", i + 1);
        printf("For Home team:\n");
        printf("\nHome team name:\n");
        scanf("%s", team1[i].h_team);
        fprintf(fp,"\nHome team:%s",team1[i].h_team);
        printf("Enter goals scored by home team:\n");
        scanf("%d", &team1[i].goals1);

        printf("Total shots by home team:\n");
        scanf("%d", &team1[i].tshot1);

        printf("Shots on target:\n");
        scanf("%d", &team1[i].ontar1);

        printf("For Away team:\n");
        printf("\nAway team name:\n");
        scanf("%s", team2[i].a_team);

        printf("Enter goals scored by away team:\n");
        scanf("%d", &team2[i].goals2);

        printf("Total shots by away team:\n");
        scanf("%d", &team2[i].tshot2);

        printf("Shots on target:\n");
        scanf("%d", &team2[i].ontar2);
    }

    printf("For La Liga:\n");
    printf("Enter number of match scores to be updated= ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)       //Enter details for Spanish League(or La Liga)
    {
        printf("Enter for Match %d:\n", i + 1);
        printf("For Home team:\n");
        printf("\nHome team name:\n");
        scanf("%s", team3[i].hm_team);

        printf("Enter goals scored by home team:\n");
        scanf("%d", &team3[i].goals3);

        printf("Total shots by home team:\n");
        scanf("%d", &team3[i].tshot3);

        printf("Shots on target:\n");
        scanf("%d", &team3[i].ontar3);

        printf("For Away team:\n");
        printf("\nAway team name:\n");
        scanf("%s", team4[i].awa_team);

        printf("Enter goals scored by away team:\n");
        scanf("%d", &team4[i].goals4);

        printf("Total shots by away team:\n");
        scanf("%d", &team4[i].tshot4);

        printf("Shots on target:\n");
        scanf("%d", &team4[i].ontar4);
    }

    do
    {
        printf("\n\n");   // Menu dashboard for users to display match summary
        printf("\n 1.Premier League\n 2.La Liga\n 3.Exit\n");
        printf("Enter your choice to display scores:\n");
        scanf("%d", &ch);

        switch (ch){
            case 1:   // To display Premier League matches
                printf("Enter the match number to display:\n");
                scanf("%d",&matno);
                matno--;
                printf("\n\n*****Premier League*******\n");
                printf("                   Home                 Away\n");
                printf("                   %-20s %-10s \n",team1[matno].h_team,team2[matno].a_team);
                printf(" Goals -             %-20d %-15d\n",team1[matno].goals1,team2[matno].goals2);
                printf("====================================================\n");
                fprintf(fp,"\n\n******Premier League*******\n");
                fprintf(fp,"                   Home                 Away\n");
                fprintf(fp,"                   %-20s %-10s \n",team1[matno].h_team,team2[matno].a_team);
                fprintf(fp," Goals -             %-20d %-15d\n",team1[matno].goals1,team2[matno].goals2);
                fprintf(fp,"====================================================\n");
                acc1=(team1[matno].ontar1*100/team1[matno].tshot1);
                acc2=(team2[matno].ontar2*100/team2[matno].tshot2);
                printf(" Total Shots -       %-20d %-15d\n Shots on Target -   %-20d %-20d\n Shot accuracy - %-22.2f %-20.2f",team1[matno].tshot1,team2[matno].tshot2,team1[matno].ontar1,team2[matno].ontar2,acc1,acc2);
                fprintf(fp," Total Shots -       %-20d %-15d\n Shots on Target -   %-20d %-20d\n Shot accuracy - %-22.2f %-20.2f",team1[matno].tshot1,team2[matno].tshot2,team1[matno].ontar1,team2[matno].ontar2,acc1,acc2);
                if(team1[matno].goals1>team2[matno].goals2){
                    printf("\n\n Winner is %s",team1[matno].h_team);
                    fprintf(fp,"\n\n Winner is %s",team1[matno].h_team);
                    }
                else if(team1[matno].goals1<team2[matno].goals2){
                    printf("\n\n Winner is %s",team2[matno].a_team);
                    fprintf(fp,"\n\n Winner is %s",team2[matno].a_team);
                    }
                
                else{
                    printf("\n\n Match has been drawn");
                    fprintf(fp,"\n\n Match has been drawn");
                }    
                break;


            case 2:    //to display La Liga matches
                printf("Enter the match number to display:\n");
                scanf("%d",&matno);
                matno--;
                printf("\n\n******La Liga*******\n");
                printf("                    Home                  Away\n");
                fprintf(fp,"\n\n******La Liga*******\n");
                fprintf(fp,"                    Home                  Away\n");
                printf("                    %-20s %-10s \n",team3[matno].hm_team,team4[matno].awa_team);
                printf(" Goals -             %-20d %-15d\n",team3[matno].goals3,team4[matno].goals4);
                printf("====================================================\n");
                fprintf(fp,"                    %-20s %-10s \n",team3[matno].hm_team,team4[matno].awa_team);
                fprintf(fp," Goals -             %-20d %-15d\n",team3[matno].goals3,team4[matno].goals4);
                fprintf(fp,"====================================================\n");
                acc1=(team3[matno].ontar3*100/team3[matno].tshot3);
                acc2=(team4[matno].ontar4*100/team4[matno].tshot4);
                printf(" Total Shots -       %-20d %-15d\n Shots on Target -   %-20d %-20d\n Shot accuracy - %-22.2f %-20.2f",team3[matno].tshot3,team4[matno].tshot4,team3[matno].ontar3,team4[matno].ontar4,acc1,acc2);
                fprintf(fp," Total Shots -       %-20d %-15d\n Shots on Target -   %-20d %-20d\n Shot accuracy - %-22.2f %-20.2f",team3[matno].tshot3,team4[matno].tshot4,team3[matno].ontar3,team4[matno].ontar4,acc1,acc2);
                if(team3[matno].goals3>team4[matno].goals4){
                    printf("\n\n Winner is %s",team3[matno].hm_team);
                    fprintf(fp,"\n\n Winner is %s",team3[matno].hm_team);
                    
                    }
                else if(team3[matno].goals3<team4[matno].goals4){
                    printf("\n\n Winner is %s",team4[matno].awa_team);
                    fprintf(fp,"\n\n Winner is %s",team4[matno].awa_team);
                    }
                
                else{
                    printf("\n\n Match has been drawn");
                    fprintf(fp,"\n\n Match has been drawn");
                }    
                break;        

            case 3:     // To exit options
                printf("\nPlease visit next time\nGoodbye\n");
                fprintf(fp,"\nPlease visit next time\nGoodbye\n");
                exit(1);
            default:
                break;
    } 
    
 }
    while(ch!=4);

    fclose(fp);
    return 0;
}