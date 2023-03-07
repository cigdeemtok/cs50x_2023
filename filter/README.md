This is problem set 4. In this problem, we have some bitmap images and we need to create some filters to apply to them.<br>
This is more comfortable version of the problem and we have 4 filters we need to implement: **grayscale, reflect, blur and edge-detection.**<br>
In this problem we have two c files. filter.c was coded for us and we needed to implement filter functions in helpers.c.<br>
And we also have a header file for us to use filter functions in filter.c and also to be able to reach contents of .bmp files.<br>
<br>
->**Grayscale** filter is to make the image black and white. For that, we take every pixels red,green and blue values, sum them up and then take the average value. We are going to assign this average value to that pixel's red,green and blue values.<br>
->**Reflect** filter is going to give mirror effect. Any pixels on the left side of the image should end up on the right, and vice versa.<br>
->**Blur** filter is going to soften the image. For this problem, we’ll use the “box blur,” which works by taking each pixel and, for each color value, giving it a new value by averaging the color values of neighboring pixels.<br>
->**Edge-detection** filter is going to detect edges in an image: lines in the image that create a boundary between one object and another. One way to achieve this effect is by applying the Sobel operator to the image.<br>
<br>
Especially, blur and edge-detection filter were more challenging. So there is a link for problem definition: **[CS50-Problem Set4](https://cs50.harvard.edu/x/2023/psets/4/filter/more/)**
