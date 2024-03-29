# RunSyncSocialiot

RunSync is a revolutionary vest that combines tactile and haptic technology to enable a novel form of social communication while engaging in physical activity, especially running. The main goal of RunSync is to improve the running experience by allowing users to communicate with one another through a series of taps and vibrations, even if they are in different spaces. The vest acts as a platform for communication, enabling users to send and receive messages through tactile sensations, creating a creative and engaging way to socialise while running.

The intended experience with RunSync is to provide users, especially novice runners, with a manageable and enjoyable way to start their running journey. By donning the RunSync vest, users can quickly locate and connect with compatible running partners at any time and place, facilitating supported and encouraged running sessions. Users of the vest can forge connections with people with similar interests and objectives by using the vest's haptic feedback and tactile technology.

When wearing RunSync, users can experience a relay race-like environment where they communicate with their companions through a series of taps. In order to facilitate communication, each tap is converted into a corresponding vibration that the recipient feels. This eliminates the need for a verbal exchange or the reliance on nonverbal cues like body language. Inspiring users to feel a sense of community and camaraderie while running, this exciting and interactive form of interaction adds a layer of connection and excitement.

The use of haptic feedback and tactile technology in RunSync is supported by academic research. MacGavin et al. (2021) developed a Protactile-Inspired Wearable Haptic Device tailored for sighted-hearing and DeafBlind individuals, utilizing vibration, pressure, and heat for communication. Another study by Chang et al. (2002) describes ComTouch, a device that enhances remote voice communication through touch by converting hand pressure into real-time vibrational intensity. These papers highlight the potential of haptic communication and tactile technology in capturing communication aspects.
Advancements in mediated social touch show promise in enhancing the quality and expanding the bandwidth of interpersonal communication (Raisamo et al., 2022). Further exploration of how haptic communication and tactile technology can be effectively employed for communication purposes is a significant topic for discussion.



# Technical implementation and specifications

## folder uno stores the c code for uno"ardWS.ino" and esp8266 code "websocket.ino"
## the webSocket folder contains the flask app and 2 html files as it requires 2 different port to commuicate the 
 1. tapping commuication via uno
 2. feeling the other person's running pace via m5stickC
## step.ino is for m5stickC input device, send ms tempo to the webSocket server
## socket_step.ino is for m5stickC output device, send vibration via port 26.

Both vests have back-and-forth tapping interactions with the use of Duino Tech Uno Wifi Dual Board and touch sensors. 
The Duino Tech Uno WiFi Dual Board is a device that combines the ESP8266 and Arduino Uno components. These components need to be programmed separately to work together. The ESP8266 acts as a client, connecting to a WebSocket for communication. It receives instructions and sends them to the Arduino Uno using serial I/O.

The Arduino Uno board has multiple ports that allow you to connect various sensors and motors. This feature enables you to express messages through physical movements and sensations.

To establish communication between devices, a Python WebSocket is hosted on a laptop, connected via a mobile hotspot. Any device connected to this WebSocket server can broadcast instructions to all other devices on the server, creating a network for simultaneous communication.

During the development process, different components and experiments were conducted. Initially, a servo motor was tested, but it didn't provide the desired tapping sensation for effective communication.

Alternative input options such as a pressure sensor or button were considered, but they couldn't simulate a friendly tap as intended.

Another experiment involved displaying a person's heart rate visually using servo motors wrapped in a sponge, but it didn't prove useful in the intended context.

Finally, the focus shifted to allowing users to sense and feel the running pace of another user. The esp32-pico, distributed as m5stickC, was used to achieve this. It connects to a separate WebSocket server and calculates the running pace based on step intervals. The pace information is then sent to another m5stickC, which controls two motors to simulate footsteps. Rapid arm movements are disregarded as running pace, while slow movements (over 1 second per step) stop the vibration.

In summary, the Duino Tech Uno WiFi Dual Board combines ESP8266 and Arduino Uno components, allowing you to create interactive experiences using various sensors and motors. Through a WebSocket server, devices can communicate and respond to instructions. The device emphasizes conveying messages through physical sensations like tapping and simulating running pace, providing opportunities for creative expression and meaningful communication.

# References
The Messaging Kettle: It’s IoTea time 
https://tidsskrift.dk/ashcc/article/download/21323/18793

A wearable haptic device for deafblind communication 
https://www.ncbi.nlm.nih.gov/pmc/articles/PMC7506622/


Introduction: Digital Touch Communication: https://link.springer.com/chapter/10.1007/978-3-030-24564-1_1


The Tactile Internet: Applications and Challenges
https://ieeexplore.ieee.org/abstract/document/6755599?casa_token=KoeCGHjgCfYAAAAA:cuF8XV5fla237wMZPzNMHePoo_4zM0agfAl0b37aa-NuNsRdfYdXg-zJjUCb34reSepHfA4raa9y
