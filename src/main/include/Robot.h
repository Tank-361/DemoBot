// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <ctre/phoenix.h>
#include <frc/XboxController.h>
#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;

 private:
  WPI_TalonSRX *leftDriveMotor1;
  WPI_TalonSRX *leftDriveMotor2;
  WPI_TalonSRX *leftDriveMotor3;
  WPI_TalonSRX *rightDriveMotor1;
  WPI_TalonSRX *rightDriveMotor2;
  WPI_TalonSRX *rightDriveMotor3;
  VictorSPX *proIntakeMotor;
  WPI_TalonSRX *shooter1;
  WPI_TalonSRX *shooter2;

  frc::XboxController *driver;
  frc::XboxController *codriver;
  
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
};
