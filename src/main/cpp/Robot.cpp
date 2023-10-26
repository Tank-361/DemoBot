// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <fmt/core.h>
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  leftDriveMotor1 = new WPI_TalonSRX(3);
  leftDriveMotor2 = new WPI_TalonSRX(7);
  leftDriveMotor3 = new WPI_TalonSRX(16);
  rightDriveMotor1 = new WPI_TalonSRX(1);
  rightDriveMotor2 = new WPI_TalonSRX(5);
  rightDriveMotor3 = new WPI_TalonSRX(6);
  proIntakeMotor = new VictorSPX(11);
  shooter1 = new WPI_TalonSRX(4);
  shooter2 = new WPI_TalonSRX(12);
  driver = new frc::XboxController(0);
  codriver = new frc::XboxController(1);
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  fmt::print("Auto selected: {}\n", m_autoSelected);

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
  if (driver->GetLeftY()>0.1 || driver->GetLeftY()<-0.1) {
    leftDriveMotor1->Set(driver->GetLeftY());
    leftDriveMotor2->Set(driver->GetLeftY());
    leftDriveMotor3->Set(driver->GetLeftY());
  } else {
    leftDriveMotor1->Set(0);
    leftDriveMotor2->Set(0);
    leftDriveMotor3->Set(0);
    }

  if (driver->GetRightY()>0.1 || driver->GetRightY()<-0.1) {
    rightDriveMotor1->Set(-driver->GetRightY());
    rightDriveMotor2->Set(-driver->GetRightY());
    rightDriveMotor3->Set(-driver->GetRightY());
  } else {
    rightDriveMotor1->Set(0);
    rightDriveMotor2->Set(0);
    rightDriveMotor3->Set(0);
    }


  double speed = (fabs(codriver->GetLeftY()>0.15)) ? codriver->GetLeftY() : 0;
  if (codriver->GetLeftY()>0.1 || codriver->GetLeftY()<-0.1) {
    shooter1->Set(codriver->GetLeftY());
    shooter2->Set(codriver->GetLeftY());
  } else {
    shooter1->Set(0);
    shooter2->Set(0);
  }
  if (codriver->GetRightY()>0.1 || codriver->GetRightY()<-0.1) {
    proIntakeMotor->Set(VictorSPXControlMode::PercentOutput, codriver->GetRightY());
    std::cout << "In Intake Motor" << std::endl;
  } else {
    proIntakeMotor->Set(VictorSPXControlMode::PercentOutput, 0);
  }
  
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
