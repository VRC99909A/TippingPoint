//define all motor ports constant variables here
/*drivetrain motor ports*/
#define FLMotorPort 1
#define FRMotorPort 10
#define BLMotorPort 19
#define BRMotorPort 16
/*ring belt motor ports*/
#define LiftMotorPort 4
/*front claw motor port*/
#define ClawMotorPort 8
/*back claw motor port*/
#define BackClawMotorPort 3
//port 4 fried
//port 5 fried
//define all sensor ports constant variables here
/**
#define GyroPort 1
**/

 //declare global motor object variables here
 /*drivetrain motor variables*/
extern pros::Motor FLMotor;
extern pros::Motor FRMotor;
extern pros::Motor BLMotor;
extern pros::Motor BRMotor;
 /*ring belt motor variables*/
extern pros::Motor LiftMotor;
/*front claw motor variables*/
extern pros::Motor ClawMotor;
/*back claw motor variables*/
extern pros::Motor BackClawMotor;

 //declare global controller object variable here
extern pros::Controller master;
extern pros::Controller partner;

//declare global sensor object variables here
/**
extern pros::ADIGyro gyro;
**/

//declare global variables that map controller joysticks for drivetrain variables
extern int LeftControl;
extern int RightControl;
extern int power;
extern int turn;

//declare drive train function prototype
/*drive train task thread function prototype*/
void DriveTrain_fn(void* param);
/*drive train functions*/
void Drive(double, int);
void Rotate(double, int);

bool AtDistanceDriveGoal(int);

//declare ring belt function prototype
void Lift_fn(void* param);
void Lift(double, int);

bool AtDistanceLiftGoal(int);

//declare front claw function prototype
void Claw_fn(void* param);
void Claw(double, int);

bool AtDistanceClawGoal(int);

//declare back claw function prototype
void BackClaw_fn(void* param);
void BackClaw(double, int);

bool AtDistanceBackClawGoal(int);


//declare functions for antonomous.cpp
/* function for red alliance side close to goal zone*/
void left();
void right();
void both();
void none();

void SkillsAuton();
/* variables and functions for auton selector */
//deckare autonselector - LED on screen auton selection indicator
extern int autonselector;
//declare string array "titles[]" as constant to store auto script function names for LED display
extern const char *titles[5];
//declare an array of function pointers for all auton script functions
extern void (*scripts[5])();
//declare auton script runner function - to be called in the main
//or you can directly call through function pointer array - scripts[autonselector]();
void LCDScriptExecute();
