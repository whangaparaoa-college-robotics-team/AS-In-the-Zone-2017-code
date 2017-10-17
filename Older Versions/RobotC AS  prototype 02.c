#pragma config(Motor,  port2,           LeftMotor,     tmotorVex269_HBridge, openLoop)
#pragma config(Motor,  port3,           RightMotor,     tmotorVex269_HBridge, openLoop)
#pragma config(Motor,  port4,           LiftMotor1,     tmotorVex269_HBridge, openLoop)
#pragma config(Motor,  port5,           LiftMotor2,     tmotorVex269_HBridge, openLoop)
#pragma config(Motor,  port6,           ClawMotor,     tmotorVex269_HBridge, openLoop)
/* Code for Abomnible Snowflakes, In the Zone robot for Vex EDR - In the zone
Writen by: Benjamin Mueggenburg

//Updates:
Update 26.09.17: Added slow down ability*/

// Drive speed is a percentage of the total speed - remote =- example 1.0 is normal speed
const float normalDrivespeed = 1.0;
const float slowedDrivespeed = 0.5;

//Drivespeed is the float that will be changed
float drivespeed = normalDrivespeed;
task main()
{
	
	while (true)
	{
		/* Drives left and right main motors */
		motor[LeftMotor] = vexRT[Ch3] * drivespeed;
		motor[RightMotor] = vexRT[Ch2] * drivespeed;

		/*Lift up */
		if(vexRT[Btn6U] == 1)
		{
			motor[LiftMotor1] = 50;
			motor[LiftMotor2] = 50;
		}
		/*Lift down */
		else if(vexRT[Btn6D] == 1)
		{
			motor[LiftMotor1] = -10;
			motor[LiftMotor2] = -10;
		}

		/*Stop lift */
		else
		{
			motor[LiftMotor1] = 0;
			motor[LiftMotor2] = 0;
		}
		/*Open claw */
		if(vexRT[Btn5U] == 1)
		{
			motor[ClawMotor] = 50;
		}

		/*Close claw */
		else if(vexRT[Btn5D] == 1)
		{
			motor[ClawMotor] = -50;
		}

		/* Stop claw */
		else
		{
			motor[ClawMotor] = 0;
		}
		// Checks to see if button 7d is down
		if (vexRT[Btn7U] ==1 || vexRT[Btn7U])
		{
			drivespeed = slowedDrivespeed;
		}
		else
		{
			drivespeed = normalDrivespeed;	
		}
	}

}
