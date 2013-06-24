TemperatureSensor
=================

Library to read cc430f5137 in Kicksat Sprite

Install to the Energia Libraries folder.

Add
~~~~~~~~
#include <temp.h>
~~~~~~~~
to the top of your code to use it.

`readTemp()` and `readTempX10()` give the temperature in units of degrees Centigrade.

`calibrateTemp()` and `setGainOffset(gain, offset)` adjust the mapping from ADUs to degrees.

Examples are included and can be opened using Energia, simply go to File->Examples->TemperatureSensor
