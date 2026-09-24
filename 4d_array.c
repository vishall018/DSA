#include<stdio.h>

int seats[2][2][3][4];

int main(){
int choice,screen,show,row,seat;
int i,j,k,count;

while(1){
printf("\n\n--- MOVIE SEAT BOOKING ---\n");
printf("1. Book Seat\n");
printf("2. Cancel Seat\n");
printf("3. Display Seats\n");
printf("4. Count Available Seats\n");
printf("5. Count Booked Seats in Screen\n");
printf("6. Exit\n");
printf("Enter choice: ");
scanf("%d",&choice);

if(choice==1){
printf("Enter Screen (1-2): ");
scanf("%d",&screen);
printf("Enter Show (1-2): ");
scanf("%d",&show);
printf("Enter Row (1-3): ");
scanf("%d",&row);
printf("Enter Seat (1-4): ");
scanf("%d",&seat);

screen--;
show--;
row--;
seat--;

if(seats[screen][show][row][seat]==1)
printf("Seat already booked\n");
else{
seats[screen][show][row][seat]=1;
printf("Seat booked successfully\n");
}
}
else if(choice==2){
printf("Enter Screen (1-2): ");
scanf("%d",&screen);
printf("Enter Show (1-2): ");
scanf("%d",&show);
printf("Enter Row (1-3): ");
scanf("%d",&row);
printf("Enter Seat (1-4): ");
scanf("%d",&seat);

screen--;
show--;
row--;
seat--;

if(seats[screen][show][row][seat]==0)
printf("Seat is not booked\n");
else{
seats[screen][show][row][seat]=0;
printf("Booking cancelled\n");
}
}
else if(choice==3){
printf("Enter Screen (1-2): ");
scanf("%d",&screen);
printf("Enter Show (1-2): ");
scanf("%d",&show);

screen--;
show--;

printf("\nSeat Layout:\n");

for(i=0;i<3;i++){
for(j=0;j<4;j++)
printf("%d ",seats[screen][show][i][j]);
printf("\n");
}

printf("1 = Booked\n");
printf("0 = Available\n");
}
else if(choice==4){
printf("Enter Screen (1-2): ");
scanf("%d",&screen);
printf("Enter Show (1-2): ");
scanf("%d",&show);

screen--;
show--;

count=0;

for(i=0;i<3;i++){
for(j=0;j<4;j++){
if(seats[screen][show][i][j]==0)
count++;
}
}

printf("Available Seats = %d\n",count);
}
else if(choice==5){
printf("Enter Screen (1-2): ");
scanf("%d",&screen);

screen--;
count=0;

for(i=0;i<2;i++){
for(j=0;j<3;j++){
for(k=0;k<4;k++){
if(seats[screen][i][j][k]==1)
count++;
}
}
}

printf("Booked Seats = %d\n",count);
}
else if(choice==6){
printf("Exit\n");
break;
}
else
printf("Invalid Choice\n");
}

return 0;
}