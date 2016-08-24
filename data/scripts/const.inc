// ***** global constants

// directions
global DI_UP       =0;
global DI_UPRIGHT  =1;
global DI_RIGHT    =2;
global DI_DOWNRIGHT=3;
global DI_DOWN     =4;
global DI_DOWNLEFT =5;
global DI_LEFT     =6;
global DI_UPLEFT   =7;

// text alignment
global TAL_LEFT  =0;
global TAL_RIGHT =1;
global TAL_CENTER=2;

global CabinetOpen; // Check if the cabinet in room 1 is open
global CabinetChecked; // Check if the cabinet has been searched
global KnowCarol; // Check if Carol said her name.
global PlantChecked; // Check if the plant has been searched
global PlantAsk; // Check if Carol scolded Zob over plant
global PlantPermission; // Check if Carol gave permission
global LoadedWeapon; // Check if gun is loaded
global SmelledPlate; // Check if Zob smelled the plate
global CanAskZif; // Check if Zob knows the plates are connected
global ZifPlate; // Check if Zif uses the plate
global PlatePressed; // Check if the plate has been pressed
global StateRoom2; // Check whether Room2 has been visited