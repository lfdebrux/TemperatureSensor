TemperatureSensor
=================

Library to read the internal temperature sensor in the TI cc430f5137 used on the Kicksat Sprite.

Install to the Energia Libraries folder.

Add `#include <temp.h>` to the top of your code to use it.

`readTemp()` and `readTempX10()` give the temperature in units of degrees Centigrade. `readTempX10()` is multiplied by 10, so you get one decimal place precision.

`calibrateTemp()` and `setGainOffset(gain, offset)` adjust the mapping from ADUs to degrees. The function is a simple linear fit, `Temperature = ADU * gain + offset`.

Examples are included and can be opened using Energia, simply go to `File->Examples->TemperatureSensor`.
