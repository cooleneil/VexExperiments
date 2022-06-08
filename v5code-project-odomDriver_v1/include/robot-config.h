using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor front_L;
extern motor front_R;
extern encoder leftEncoder;
extern encoder rightEncoder;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );