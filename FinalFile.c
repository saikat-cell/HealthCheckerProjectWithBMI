#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<windows.h>

struct USER{
    char name[50];
    int pass;
    float lastBMI;
};

typedef struct {
    char name[50];
    int calories;
}dietItem;

dietItem dietItems[]={
    {"Apple", 52},
    {"Banna", 96},
    {"Carrot", 41},
    {"Orange", 43},
    {"Chicken Breast", 165},
    {"Salmon", 206},
    {"Broccoli", 55},
    {"Spinach", 23},
    {"Rice", 130},
    {"Pasta", 210},
    {"Egg", 70},
    {"Milk", 50},
    {"Bread", 80},
    {"Chicken Thigh", 140},
    {"Beef", 200},
    {"Pork", 180},
    {"Shrimp", 120},
    {"Tofu", 80},
    {"Lentils", 230},
    {"Quinoa", 150},
    {"Almonds", 170},
    {"Walnuts", 180},
    {"Greek Yogurt", 100},
    {"Avocado", 160},
    {"Sweet Potato", 70},
    {"Brown Rice", 110},
    {"Oatmeal", 100},
    {"Grilled Chicken", 140},
    {"Grilled Fish", 120},
    {"Turkey Breast", 140},
    {"Cottage Cheese", 80},
    {"Peanut Butter", 190},
    {"Banana Smoothie", 170},
    {"Protein Shake", 150},
    {"Green Tea", 0},
    {"Coffee", 0},
    {"Water", 0}
};

#define DIET_ITEMS_COUNT (sizeof(dietItems) / sizeof(dietItem))

void suggestFood(float caloriesNeeded) {
    system("cls");
    for(int i = 0; i < DIET_ITEMS_COUNT; i++) {
        if(dietItems[i].calories <= caloriesNeeded) {
            printf("\t\t%s - %d calories\n", dietItems[i].name, dietItems[i].calories);
        }
    }
    printf("\n\t\tYou need %f more calories. Here are some suggestions:\n", caloriesNeeded);
    printf("\n");
}

void displayDietChart() {
    system ("cls");
        printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Display DietChart \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    for(int i = 0; i < DIET_ITEMS_COUNT; i++) {
        printf("\t\t%d. %s - %d calories\n", i + 1, dietItems[i].name, dietItems[i].calories);
    }
    printf("\n");
    int n;
    float totalCalories =0;
    printf("\t\tEnter the number of your diet choice(if done->ctrl+z): ");
    while(scanf("%d", &n) == 1) {
        printf("\t\tEnter the number of your diet choice(if done->ctrl+z): ");
        totalCalories += dietItems[n - 1].calories;
    }
    system ("cls");
    float caloriesNeeded = 2500 - totalCalories;
    if(caloriesNeeded > 0) {
        suggestFood(caloriesNeeded);
    } else {
        printf("\n\t\tYour diet is perfect!\n");
    }
}

struct USER newUser;
struct USER loginUser;
struct USER user;

void firstPage() {
    printf("\t\t\x1b[1;36m===============================================================\n");
    printf("\t\t\x1b[1;36m||                                                           ||\n");
    printf("\t\t\x1b[1;36m||                    \x1b[1;32mW E L C O M E   T O\x1b[1;36m                    ||\n");
    printf("\t\t\x1b[1;36m||        \x1b[1;32mH E A L T H   C H E C K E R   P R O J E C T\x1b[1;36m        ||\n");
    printf("\t\t\x1b[1;36m||                                                           ||\n");
    printf("\t\t\x1b[1;36m||       \x1b[1;35m_    _   _                      /\\                  \x1b[1;36m||\n");
    printf("\t\t\x1b[1;36m||      \x1b[1;35m| |  | | | |    _       __      / /                  \x1b[1;36m||\n");
    printf("\t\t\x1b[1;36m||      \x1b[1;35m| |__| | | |    \\ \\    /  \\    / /                   \x1b[1;36m||\n");
    printf("\t\t\x1b[1;36m||      \x1b[1;35m|  __  | | |     \\ \\  / /\\ \\  / /                    \x1b[1;36m||\n");
    printf("\t\t\x1b[1;36m||      \x1b[1;35m| |  | | | |____  \\ \\/ /  \\ \\/ /                     \x1b[1;36m||\n");
    printf("\t\t\x1b[1;36m||      \x1b[1;35m|_|  |_| |______|  \\__/    \\__/                      \x1b[1;36m||\n");
    printf("\t\t\x1b[1;36m||                                                           ||\n");
    printf("\t\t\x1b[1;36m===============================================================\n");
    printf("\t\t\x1b[3;36m||                                                           ||\n");
    printf("\t\t\x1b[3;36m||                      Anongyo && Niloy                     ||\n");
    printf("\t\t\x1b[1;36m||                                                           ||\n");
    printf("\t\t\x1b[1;36m===============================================================\n");
    printf("\x1b[0m");
    Sleep(2000);
}

void signup()
{
             system("cls");
             printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2Sign up\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
             printf("\t\tSign up condition : \n\n");
             printf("\t\t1.Username must be unique\n");
             printf("\t\t2.Password must be numeric\n\n");
             printf("\t\tYour user name : ");
             scanf("%s",newUser.name);
             printf("\t\tYour Password  : ");
             scanf("%d", &newUser.pass);
             FILE *fptr = fopen("password.txt", "r");
             int f=1;
             while (fscanf(fptr, "%s\n%d\n%f\n", user.name, &user.pass, &user.lastBMI) != EOF) {
                if(strcmp(user.name,newUser.name)==0 ){
                    system("cls");
                    printf("\n\t\tAccount already exist\n");
                    f=0;
                    break;
                }
            }
             fclose(fptr);
             if(f==1){
             fptr = fopen("password.txt", "a");
             newUser.lastBMI = 0.0;
             fprintf(fptr, "%s\n%d\n%.2f\n", newUser.name, newUser.pass, newUser.lastBMI);
             fclose(fptr);
             printf("\n\t\tSign up successful.\n");
            }
}

int homeMenu()
{
     int n;
        printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2welcome to project health checker\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        printf("\t\t1: Log in\n");
        printf("\t\t2: Sign up\n");
        printf("\t\t3: Exit\n");
        printf("\t\tEnter your choice: ");
        scanf("%d", &n);
       // getchar();
        return n;
}

int login()
{
            system("cls");
            printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2Log in\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
            printf("\t\tEnter your user name : ");
            scanf("%s", loginUser.name);
            printf("\t\tEnter your password : ");
            scanf("%d", &loginUser.pass);

            FILE* fptr=fopen("password.txt","r");

            int id=0;

            if (fptr == 0) {
                    printf("\n\t\tNo users found. Please sign up first.\n");

                }

                while (fscanf(fptr, "%s\n%d\n%f\n", user.name, &user.pass, &user.lastBMI) != EOF) {
                if(strcmp(user.name,loginUser.name)==0 && user.pass==loginUser.pass){
                    printf("\n\t\tLoading");
                    for (int i = 0; i <= 6; i++) {
                    Sleep(200);
                    printf(".");
                }
                    system("cls");
                    printf("\n\t\tLogin Successful\n\n");
                    id=1;
                    system("cls");
                    break;
                }
            }
            fclose(fptr);
            if(id==0){
                system("cls");
                printf("\n\t\tLog in not successful. Please check your username and password.\n");
                return 0;
            }else{
                return 1;
            }
}

float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

void updateBMI(float newBMI) {
    FILE *fptr = fopen("password.txt", "r+");
    if (fptr == NULL) {
        printf("\n\t\tError opening file.\n");
        return;
    }
    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("\n\t\tError creating temporary file.\n");
        fclose(fptr);
        return;
    }

    while (fscanf(fptr, "%s\n%d\n%f\n", user.name, &user.pass, &user.lastBMI) != EOF) {
        if (strcmp(user.name, loginUser.name) == 0 && user.pass == loginUser.pass) {
            user.lastBMI = newBMI;
        }
        fprintf(temp, "%s\n%d\n%.2f\n", user.name, user.pass, user.lastBMI);
    }

    fclose(fptr);
    fclose(temp);
    remove("password.txt");
    rename("temp.txt", "password.txt");
}

void displayBMIMeter(float bmi){
        if(bmi<18.5){
            printf("\t\t--->BMI Category : Underweigth\n\n");
        }else if(bmi>=18.5 && bmi<24.9){
            printf("\t\t--->BMI Category : Normal weight\n\n");
        }else if(bmi>=25 && bmi<29.9){
            printf("\t\t--->BMI Category : Overweight\n\n");
        }else{
            printf("\t\t--->BMI Category : Obesity\n\n");
        }
}

void profile() {
    char name[50];
    float weight, height;
    int age;
    float bmi;
    system("cls");
    printf("\t\tEnter your profile details\n");
    printf("\t\tName: ");
    scanf("%s", name);
    printf("\t\tWeight (kg): ");
    scanf("%f", &weight);
    printf("\t\tHeight (m): ");
    scanf("%f", &height);
    printf("\t\tAge: ");
    scanf("%d", &age);

    bmi = calculateBMI(weight, height);
    printf("\n\t\t--->Hello %s, your BMI is %.2f\n", name, bmi);
    displayBMIMeter(bmi);

    updateBMI(bmi);
    printf("\n\t\tProfile update successful.\n");

}

int loginInnerChoice(){
            int choice;
            printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2welcome to project health checker\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
            printf("\t\t1. Calculate BMI\n");
            printf("\t\t2. View Diet Chart\n");
            printf("\t\t3. View Workout Routine\n");
            printf("\t\t4. View Caloric Chart\n");
            printf("\t\t5. Monitor Health Condition\n");
            printf("\t\t6. Exit\n");
            printf("\t\tEnter your choice: ");
            scanf("%d", &choice);
            return choice;
}

void WorkoutRoutine(){
    int day;
    system ("cls");
    printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2Workout Routine\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\n\t\t1. Monday\n");
    printf("\t\t2. Tuesday\n");
    printf("\t\t3. Wednesday\n");
    printf("\t\t4. Thursday\n");
    printf("\t\t5. Friday\n");
    printf("\t\t6. Saturday\n");
    printf("\t\t7. Sunday\n");
    printf("\t\tSleep : Aim for 7-9 hours of sleep per night to aid recovery and overall health\n\n");
    printf("\t\tEnter your choice : ");
    scanf("%d", &day);
    system("cls");
    switch (day)
    {
    case 1:
        printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Monday \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        printf("\n\t\tWarm-Up:\n\t\t\t5-10 minutes of light cardio (jogging, jumping jacks, or brisk walking)\n");
        printf("\t\tWorkout: \n");
        printf("\t\t\tSquats: 3 sets of 12 reps\n\t\t\tPush-Ups: 3 sets of 10-15 reps\n\t\t\tBent Over Rows (using dumbbells or resistance bands): 3 sets of 12 reps\n\t\t\tPlank: 3 sets, hold for 30-60 seconds\n\t\t\tLunges: 3 sets of 12 reps (each leg)\n\t\t\tDumbbell Shoulder Press: 3 sets of 12 reps\n");
        printf("\t\tCool-Down:\n\t\t\t5-10 minutes of stretching (focus on the muscles worked)\n\n");
        break;
    case 2:
        printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Tuesday \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        printf("\n\t\tWarm-Up:\n\t\t\t5-10 minutes of dynamic stretching (leg swings, arm circles)\n");
        printf("\t\tWorkout:\n\t\t\t30-45 minutes of moderate-intensity cardio (running, cycling, swimming, or a cardio class)\n");
        printf("\t\tCool-Down:\n\t\t\t5-10 minutes of light stretching\n\n");
        break;
    case 3:
        printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Wednesday \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        printf("\n\t\tWorkout:\n\t\t\t30-60 minutes of low-intensity activities like walking, yoga, or a stretching routine\n\n");
        break;
    case 4:
        printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Thursday \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        printf("\n\t\tWarm-Up:\n\t\t\t5-10 minutes of light cardio\n");
        printf("\n\t\tWorkout:\n\t\t\tPull-Ups or Lat Pulldowns: 3 sets of 8-12 reps\n\t\t\tDumbbell Bench Press: 3 sets of 12 reps\n\t\t\tTricep Dips: 3 sets of 10-15 reps\n\t\t\tDumbbell Bicep Curls: 3 sets of 12 reps\n\t\t\tLateral Raises: 3 sets of 12 reps\n\t\t\tRussian Twists: 3 sets of 20 reps (each side)\n");
        printf("\t\tCool-Down:\n\t\t\t5-10 minutes of stretching\n\n");
        break;
    case 5:
        printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Friday \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        printf("\t\tWarm-Up:\n\t\t\t5-10 minutes of dynamic stretching\n");
        printf("\t\tWorkout:\n\t\t\t30-45 minutes of moderate to high-intensity cardio (interval training, HIIT, or a cardio machine)\n");
        printf("\t\tCool-Down:\n\t\t\t5-10 minutes of light stretching\n\n");
        break;
    case 6:
        printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Saturday \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        printf("\t\tWarm-Up:\n\t\t\t5-10 minutes of light cardio\n");
        printf("\t\tWorkout:\n\t\t\tDeadlifts: 3 sets of 12 reps\n\t\t\tLeg Press: 3 sets of 12 reps\n\t\t\tCalf Raises: 3 sets of 15 reps\n\t\t\tGlute Bridges: 3 sets of 15 reps\n\t\t\tBulgarian Split Squats: 3 sets of 12 reps (each leg)\n\t\t\tLeg Curls: 3 sets of 12 reps\n");
        printf("\t\tCool-Down:\n\t\t\t5-10 minutes of stretching\n\n");
        break;
    case 7:
        printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Sunday \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        printf("\n\t\tWorkout:\n\t\t\tOptional light activities like walking, gentle yoga, or recreational sports\n\n");
        break;
    default:
        printf("\n\t\tPlease enter a correct choice\n\n");
        break;
    }

}

void displayCaloricChart(){
    int x;
    printf("\n\t\tWhat kind of exercise you take : \n");
    printf("\t\t1. little or no exercise\n");
    printf("\t\t2. light exercise/sports 3-5 days/week\n");
    printf("\t\t3. intense exercise/sports 6-7 days a week\n\n");
    printf("\t\tEtner your choice : ");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        printf("\n\t\tAge Group (years)           Women (calories/day)            Men (calories/day)\n");
        printf("\t\t------------------------------------------------------------------------------\n");
        printf("\t\t19-25                       1,800-2,000                     2,400-2,600\n");
        printf("\t\t26-30                       1,800-2,000                     2,400-2,600\n");
        printf("\t\t31-50                       1,800                           2,200-2,400\n");
        printf("\t\t51+                         1,600                           2,000-2,200\n\n");
        break;
    case 2:
        printf("\n\t\tAge Group (years)           Women (calories/day)            Men (calories/day)\n");
        printf("\t\t------------------------------------------------------------------------------\n");
        printf("\t\t19-25                       2,000-2,200                     2,600-2,800\n");
        printf("\t\t26-30                       2,000-2,200                     2,600-2,800\n");
        printf("\t\t31-50                       2,000                           2,400-2,600\n");
        printf("\t\t51+                         1,800                           2,200-2,400\n\n");
        break;
    case 3:
        printf("\n\t\tAge Group (years)           Women (calories/day)            Men (calories/day)\n");
        printf("\t\t------------------------------------------------------------------------------\n");
        printf("\t\t19-25                       2,200-2,400                     2,800-3,000\n");
        printf("\t\t26-30                       2,200-2,400                     2,800-3,000\n");
        printf("\t\t31-50                       2,200                           2,600-2,800\n");
        printf("\t\t51+                         2,000-2,200                     2,400-2,600\n\n");
        break;
    default:
        printf("\n\t\tPlease enter a right choice.\n");
        break;
    }
}

void monitorHealthCondition(){
    printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Monitor Health Condition \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    float oldBMI,currentBMI;
    printf("\t\tEnter your BMI Minimum 10 days ago : ");
    scanf("%f", &oldBMI);
    printf("\t\tEnter your current BMI : ");
    scanf("%f", &currentBMI);

    if(currentBMI>=18.5 && currentBMI<=24.9 && (oldBMI>25 || oldBMI<18.5)){
        printf("\n\t\t--->your health condition is much better than before.");
        printf("\n\t\t--->Maintain current caloric intake and activity level to sustain healthy weight.\n\n");
    }else if(currentBMI<18.5){
        printf("\n\t\t--->Focus on nutrient-dense foods and possibly higher calorie intake to gain weight\n\n");
    }else if(currentBMI>=18.5 && currentBMI<=24.9){
        printf("\n\t\t--->You can continue your calorie chart and workout routine\n\n");
    }else if(currentBMI>24.9 && currentBMI<30){
        printf("\n\t\t--->Consider a slight caloric deficit and increased physical activity to lose weight gradually.\n\n");
    }else if(currentBMI>=30){
        printf("\n\t\t--->You should be more health conscious, follow exercise and calorie chart properly and consult doctor\n\n");
    }

}

void GoOn(){
    char p;
    printf("\t\tPress any key and enter to continue:");
    scanf(" %c", &p);
    return;
}

int main()
{

    char loginName[100];
    int loginPass;
    int userCount = 0;

    FILE* fptr = fopen("userDB.txt", "r");
    if(fptr == 0) {
        fptr = fopen("userDB.txt", "w");
    }
    fclose(fptr);
    //firstPage();
    system ("cls");
    system("color 3");
    while(1){

        switch (homeMenu())
        {

        case 1 :
            // >>log in //

            if(login()){
            while (1){
                ///>>Inner choice of BMI///

            switch (loginInnerChoice()) {
                case 1:
                    profile();
                    GoOn();
                    system("cls");
                    break;
                case 2:
                    system ("cls");
                    displayDietChart();
                    GoOn();
                    system("cls");
                    break;
                case 3:
                    WorkoutRoutine();
                    GoOn();
                    system("cls");
                    break;
                case 4:
                    system("cls");
                    displayCaloricChart();
                    GoOn();
                    system("cls");
                    break;
                case 5:
                    system("cls");
                    monitorHealthCondition();
                    GoOn();
                    system("cls");
                    break;
                case 6:
                     printf("\n\t\tThank you\n");
                     exit(0);
                default:
                    printf("\n\t\t--->Invalid choice! Please try again.\n\n");
            }

        }

    }
            break;

        case 2 :

            signup();
            GoOn();
            system("cls");
            break;

        case 3 :

            printf("\n\t\tThank you\n");
            return 0;

        default:
            system("cls");
            printf("\n\t\tValue doesn't exist\n");
            printf("\t\tPlease enter a correct choice\n");
            break;
        }
    }

    printf("\n\t\tThank you\n");

    return 0;
}

