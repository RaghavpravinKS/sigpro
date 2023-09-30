# About
This is the repository for our first assignment of the Signals Systems and Random Processes course under [Prof. Nithin V George](https://iitgn.ac.in/faculty/ee/fac-nithin). This repository contains all files related to our assignment. 

## Team Members
---------------------------
- Raghavpravin K S
- Pannala Naga Sheshu Reddy
- Pavan Deekshith Doddi

## Objective of our project
To design an Android/iOS app for child safety monitoring. We aim to create an app that detects overspeeding, accidents, and crossing of boundaries of a child riding a bicycle. 

## Simulink Model
We've created a Simulink model that takes input from the phone's sensors and uses it to detect crashes, overspeeding, and boundary crossings for bicycle monitoring.

It continuously monitors the data from various sensors such as Gyroscope, Accelerometer, GPS sensor, Camera, and microphone to get a sense of what's happening around the phone. 

## How and Where we stated?
### Raw Data Collection
We first wanted to visualize the data from various sensors, how they changed while the phone is in the pocket of the person riding a bicycle. The sensors we thought that would be helpfull for fall detection are Gyroscope, Accelermoeter, Magnetometr and GPS sensor. So we went on to collect data for a set of 7 different trips with mobile phone in the pocket of the person.
### Noise
After collecting the data for various trips the first thing we observed was that each and every sensors' data had a huge amount of noise attenuated to it, disabling us to look at the mere details of the data.
This is how the raw data looked when we tried to plot it in MATLAB;
Data from accelerometer:
Data from magnetometer:
Data from gyroscope:
DAta from GPS sensor:

So to observe them we must first remove the noise. After spending hours on smoothing and cleansing the data we arrived at this quality:
Data from accelerometer:
Data from magnetometer:
Data from gyroscope:
DAta from GPS sensor:
### Observations from data
As you can see from the above data, when a person is riding a bicycle his/her leg goes up and down in an almost periodic manner to pedal the cycle. Due to this periodic motion of legs we can observe a nice sinusoidal like pattern in almost all sensors' data. But this is not the part of data we are interested in, we want to find and detect some special features corresponding to a fall or accident; when we observe the data after the end of those sinusoidal like waveforms those are the ones corresponding to the activities that happened after the cycle stopped. As we were the ones collecting the data, we also recoreded a video to to keep track of the timeline.
Inorder to detect a fall or accident one has to focus on this part of the signal and try to extract some useful features. By keen observation we concluded there is a sudden surge in accelerations and angular velocities provided by the gyroscope and accelerometer. Now our goal is to set some threshold value to detect this sudden surge in change of these values. The naive approach to these kind of problems is setting a value by observing the reading from the data above and testing it for tweaking it. But his approach may not work in all scenarios. Our approach is a bit extended version of this idea.
What we did was, we wanted our threshold value to be adjusted according to the surrounding according to the changes in parameters of the surroundings. So we employed a moing average average filter and

## Challenges faced
While we started to solve our problem statement, we encountered many problems
#### Sensor Integration and Data Synchronization
We faced many problems while collecting raw data from sensors and plotting the results to look at the variations of while riding a bicycle.
#### Real-time Processing
Processing the data real-time was also a tedious task as the code or simulink file we created has to run as a standallone on the target hardware (Android Phone), due to this we were not able to store any data to process it on the phone. Due to this everything has to be done in real time with help of filters an7d zero post-processing.
#### Algorithm Development and Complexity
Many implementations of filtering algorithms needed an array od data to be first stored to be able to run through the algorithm. But this was not at all possible within the Android Support package for Simulink.
