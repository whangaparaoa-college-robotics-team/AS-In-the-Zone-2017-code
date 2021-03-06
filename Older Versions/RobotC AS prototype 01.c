#pragma config(Motor,  port2,           LeftMotor,     tmotorVex269_HBridge, openLoop)
#pragma config(Motor,  port3,           RightMotor,     tmotorVex269_HBridge, openLoop)
#pragma config(Motor,  port4,           LiftMotor1,     tmotorVex269_HBridge, openLoop)
#pragma config(Motor,  port5,           LiftMotor2,     tmotorVex269_HBridge, openLoop)
#pragma config(Motor,  port6,           ClawMotor,     tmotorVex269_HBridge, openLoop)
/* Code for Abomnible Snowflakes, In the Zone robot for Vex EDR - In the zone*/
/* This robot has a double bar lift (with two motors acting as the lift). The chassis is a standard 'U' shape (with 2 motors - left and right). 
At the end of the double bar lift is a standard vex claw (with one motor) */
task main()
{
	while (true)
	{
		/* Drives left and right main motors */
		motor[LeftMotor] = vexRT[Ch3];
		motor[RightMotor] = vexRT[Ch2];

		/*Lift up */
		if(vexRT[Btn6U] == 1)
		{
			motor[LiftMotor1] = 50;
			motor[LiftMotor2] = 50;
		}
		/*Lift down */
		else if(vexRT[Btn6D] == 1)
		{
			motor[LiftMotor1] = -50;
			motor[LiftMotor2] = -50;
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
	}

}
