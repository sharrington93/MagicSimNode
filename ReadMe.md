## First Code ##
This is a test bed for the c2000 embedded coder. Most commits will be different implementations of things as I learn.

### HELP!

-  Remember to run `checkEnvSetup('ccsv5','f28035')` This will configure things if it is not working.
-  Try loading the Embedded_Config.mat file



## Workflow
- Create control code in <Project>_Control.
- Test with <Project>_ControlHarness by simulating in simulink and programming to processor and checking consistency/timing. This is like software in the loop
- Create In hardware code in <Project>_InHardware. Processor code that converts sensor inputs to data used by control code.  
-  Test In Hardware code in <Project>_InHardware_CAN_Enable. Make sure the outputs are what the control code needs.
-   Create Out hardware code in <Project>_OutHardware. Processor code takes control code output and affects world.
-  Test Out Hardware code in <Project>_OutHardware_CAN_Enable. Make sure the it takes in what the control code outputs. 
-  Test full code in <Project>_FullHarness.
-  Program processor with <Project> when done.