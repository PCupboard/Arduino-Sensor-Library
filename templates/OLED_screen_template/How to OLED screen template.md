1. Include library:             <OLED_display.h>;
2. Create object:               OLED_display display;
3. Initialize screen:           display.initializeDisplay();
4. Update screen after writing: display.updateDisplay();

# Extra Methods You Can Use:
.clear() | positions cursor to (0, 0) and clears entire screen.
.drawOnScreen() | Takes in two variables, one for the text on screen and the other for the value on the screen.


# Variables You Can Use:
colorWhite | a white color you can use for the display when drawing text/objects
