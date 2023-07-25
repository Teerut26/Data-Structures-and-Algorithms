#include <stdio.h>

int main()
{
    char names[5][100];
    int scores[5];
    double sum = 0.0;
    
    for (int i=0;i<=4;i++) {
      int score;
      
      printf("person %d = ",i+1);
      scanf("%s %d",names[i], &score);
      
      scores[i] = score;
      sum += score;
    }    

    float avg = sum/5;

    for (int i=0;i<=4;i++) {
      if(scores[i] > avg) {
       printf("name: %s score: %d",names[i],scores[i]);
      }
    }

    return 0;
}

