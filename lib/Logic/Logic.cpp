/* This is the logic file where the functions for main.cpp are made
-------------------------------------------------------------------

Navigate is used to move around the maze
Record is used to collect the details about the tile and add it to the array

-------------------------------------------------------------------
*/

void Navigate() {
    // ------------ Navigate ------------
  // if(!therm.spotHeat(30)) {
    if(lrfs.average(0, 1) > 100) {
      motors.update(150, 150, IMUCorrection);
      // colorWipe(strip.Color(BLUE), 1);

      // light sensors
      if(light.light[1] > 600) {
        // staaaapp, and go back
        motors.update(0, 0, IMUCorrection);
        motors.update(-100, -100, IMUCorrection);
        delay(1000);

        // Check turn and Turn
        if(lrfs.average(2, 4) > lrfs.average(3, 5)) {
          direction = mod(direction + 90, 360);
          IMUCorrection = round(IMUPID.update(imu.horizontalHeading, direction, 0));
          while(!motors.setOrientation(IMUCorrection)) {
            update();
          }
        }
        else if(lrfs.average(3, 5) > lrfs.average(2, 4)) {
          direction = mod(direction - 90, 360);
          IMUCorrection = round(IMUPID.update(imu.horizontalHeading, direction, 0));
          while(!motors.setOrientation(IMUCorrection)) {
            update();
          }
        }
      }
    }
    // normal turn
    else {
      if(lrfs.average(2, 4) > lrfs.average(3, 5)) {
        // colorWipe(strip.Color(RED), 1);
        direction = mod(direction + 90, 360);
        IMUCorrection = round(IMUPID.update(imu.horizontalHeading, direction, 0));
        while(!motors.setOrientation(IMUCorrection)) {
          update();
          }
        }
        else if(lrfs.average(3, 5) > lrfs.average(2, 4)) {
          // colorWipe(strip.Color(GREEN), 1);
          direction = mod(direction - 90, 360);
          IMUCorrection = round(IMUPID.update(imu.horizontalHeading, direction, 0));
          while(!motors.setOrientation(IMUCorrection)) {
            update();
        }
      }
    }
  // else {
  //   update();
  //   motors.update(0, 0, IMUCorrection);
  //   colorWipe(strip.Color(GREEN), 1);
  //   delay(100);
  //   colorWipe(strip.Color(0, 0, 0), 1);
  //   delay(100);
  //   colorWipe(strip.Color(GREEN), 1);
  //   delay(100);
  //   colorWipe(strip.Color(0, 0, 0), 1);
  //   delay(100);
  //   colorWipe(strip.Color(GREEN), 1);
  //   delay(100);
  //   colorWipe(strip.Color(0, 0, 0), 1);
  //   delay(100);
  //   !therm.spotHeat(30);
  //   therm.value[0] = 0;
  // }
}

void Record() {

}