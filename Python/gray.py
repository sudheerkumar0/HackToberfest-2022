from email.policy import default
from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont


text = input("Enter What You want to type: ")
im = Image.new("L", (1024, 1024), color="#454545")
im_text = ImageDraw.Draw(im)
myFont = ImageFont.truetype("arial.ttf", 60)
im_text.text((512,950), text, font=myFont, stroke_fill=1 )

im.show()