Project summary:
An irrigation system that uses temperature sensors, soil humidity and time of day, checking if it is necessary to irrigate the garden, thus saving water by reducing water evaporation in the soil.
Project description:
 

In the developed project, a skillful system is created to trigger an irrigation system applying the drip technique, whenever a soil moisture measurement is presented. Using Franzininho Wifi and specific sensors to guarantee the safety and integral functioning of the project, it is possible to monitor and, if necessary, adapt the system, changing the schedule according to the needs of each plantation, prominently making it possible to minimize and even solve production problems caused as a result. by climatic problems that directly affect soil and water availability.

Image 1: Prototype.


![IMG_20211231_111125-200x113](https://user-images.githubusercontent.com/83675952/155904631-3123949b-3c01-461d-86ac-d0161714edd2.jpg)

Development history:
The idea of the project was given to a need in the dry months in the southeast region in the year 2021. Water is an essential resource for human life and when we suffer from a period of drought we reflect on how we use it and on the waste of everyday life.

researching the subject, I found a lot of information about forms of irrigation and how to avoid waste.

Irrigation
An irrigation system must be made in a sustainable way, aiming at the best use of water, avoiding waste, consequently saving other factors such as soil depletion and energy use. In the case of drip irrigation, the process is done by moistening the soil next to the plant, in a way that saves water, and satisfies the needs of the plantation. The lack of water can slow down the growth of plants and damage the leaves, while the excess “drowns” the roots, making oxygenation difficult and contributing to the appearance of fungi and diseases. The secret is to water slowly, stopping when the water starts to seep into the soil.

Best time for irrigation 
The best time to water the plants is between the early hours of the day and after 15:00.

Shield Franzinho Wifi
To facilitate connections and prototyping, a shield was developed for Franzininho Wifi using a 4×6 cm double-sided perforated plate and pin bar, in it we have:

VCC (3v3): Red color bar
GND: Black color bar
 Esp32: Yellow color bar
Image 2: Top view of shield and Franzinho Wifi.

![IMG_20211231_002315-200x113](https://user-images.githubusercontent.com/83675952/155904640-7db0211f-3d5f-4520-b096-092e6acf15f0.jpg)



Image 3: Side view of shield and Franzinho Wifi.

![IMG_20211231_002304-200x113](https://user-images.githubusercontent.com/83675952/155904650-e8914b65-fefa-4aa4-b1ae-22be8ef0e93c.jpg)


In order to save water, a rainwater collector was developed, consisting of a cylindrical container with a filter attached to the lid, an ice cream pot was used as a container and a cloth as a filter.

Image 4: Tank with rainwater collection filter.

![IMG_20211226_173655526-200x113](https://user-images.githubusercontent.com/83675952/155904652-d6bfbde4-df35-4fe8-a563-22505ebf0f34.jpg)
 

To irrigate, a hose was used and holes were drilled to the ends.

Image 5: hose with holes.

 ![IMG_20211226_155719753-200x113](https://user-images.githubusercontent.com/83675952/155904655-152cb92a-4da4-40ba-ac6c-f62baa1f903f.jpg)


Hardware:
Fritzing Schematic
 


Image 6: Fritzing schematic.

.![embarcados-200x225](https://user-images.githubusercontent.com/83675952/155904672-13833fbb-6576-4784-bb8c-89da0e40c647.png


 

List of materials

Table 1: List of materials.

The amount

Component

1	little Wifi
two	Soil moisture sensor
1	DHT11
1	relay module
1	DS3231
1	level buoy
1	OLED display
1	3v3 water pump
A 4K7 resistor was soldered on the SDA pin and on the SCL pin (I2C communication), without them it is not possible to carry out I2C communication.

Image 7: 4K7 resistors.

![IMG_20211231_114212-200x113](https://user-images.githubusercontent.com/83675952/155904681-1f1c6369-c6b2-4801-b1f4-a0bb226ea7df.jpg)


