/*
 * app.h
 *
 * Created: 8/9/2022 1:44:34 AM
 *  Author: Abdallah
 */ 


#ifndef APP_H_
#define APP_H_

#define TRAFFIC_NORMAL_MODE	0u
#define TRAFFIC_PEDESTRIAN_MODE	1u

#define CARS_GREEN_LED	0u
#define CARS_YELLOW_LED	1u
#define CARS_RED_LED	2u

#define PEDESTRIAN_GREEN_LED	8u
#define PEDESTRIAN_YELLOW_LED	9u
#define PEDESTRIAN_RED_LED	10u

#define PEDESTRIAN_BUTTON	26u

#define ON	1u
#define OFF 0u

void appStart(void);



#endif /* APP_H_ */