# console_graphics
Graphics for consoles

An example program "displaybmp.c" is included to demonstrate the capabilities of the ascii renderer.

To run:

```./displaybmp file.bmp```

Where file.bmp is a bitmap image of arbitrary size. The size of the bitmap will determine the number of characters wide and tall the image will be displayed as on the console. The width will be the `bmp_width/8 + 1` and the height will be `bmp_height/13 + 1`.
