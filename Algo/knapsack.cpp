#define WEIGHT_BINS  100

//  solve_knapsack
// 
//  inputs:
//    nn - number of items
//    v - vector of item values
//    w - vector of item weights
//    W - capacity of the knapsack
//    choice - pointer to a valid memory block in which to place the best found selection
//  output:
//    best found value of the knapsack
double solve_knapsack(int nn, double *v, double *w, double W, int *choice)
{
  int i,j; //loop variables
  double *sol_table; //solution table
  double w_step = W / WEIGHT_BINS;
  
  //printf("W step is %g, %d items\n", w_step, nn);
  int rl = WEIGHT_BINS+1;  //row length
  sol_table = (double *)malloc(sizeof(double) * (nn+1) * rl);

  int *prev_choice = (int *)malloc(sizeof(int) * nn * rl);
  int *cur_choice = (int *)malloc(sizeof(int) * nn * rl);

  //take care of the first row for zero items
  for (i=0; i < rl; i++)
    sol_table[i] = 0;
  memset(cur_choice, 0, sizeof(int)*nn*rl);

  //now, start increasing the number of items considered
  for (i=1; i < (nn+1); i++) {
    sol_table[i*rl] = 0; //set entry (i,0) = 0

    //for i items, what is best knapsack as weight increases
    for (j=1; j < rl; j++) {
      double curw = w_step*j;
      if (w[i-1] <= curw) {
	int temp = (int)floor((curw - w[i-1])/w_step);
	//check to see if new item should be in optimal solution
	if ((v[i-1] + sol_table[(i-1)*rl + temp]) > sol_table[(i-1)*rl + j]) {
	  sol_table[i*rl + j] = v[i-1] + sol_table[(i-1)*rl + temp];
	  memcpy(&cur_choice[j*nn], &prev_choice[temp*nn], sizeof(int)*nn);
	  cur_choice[j*nn + i-1] = 1;
	}
	else {
	  sol_table[i*rl + j] = sol_table[(i-1)*rl + j];
	  memcpy(&cur_choice[j*nn], &prev_choice[j*nn], sizeof(int)*nn);
	}
      }
      else { //new item i doesn't even fit
	sol_table[i*rl + j] = sol_table[(i-1)*rl + j]; 
	memcpy(&cur_choice[j*nn], &prev_choice[j*nn], sizeof(int)*nn);
      }
    }

    memcpy(prev_choice, cur_choice, sizeof(int)*nn*rl); //update prev choice
  }

  /*
  for (i=0;i<(nn+1);i++) {
    for (j=0; j&ltrl; j++) {
      printf("%g ", sol_table[i*rl + j]);
    }
    printf("\n");
  } */

  memcpy(choice, &cur_choice[(rl-1)*nn], sizeof(int)*nn);
  double to_return = sol_table[(nn+1)*rl - 1];

  free(sol_table);
  free(prev_choice);
  free(cur_choice);

  return to_return;
}
