from selenium import webdriver 
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time

browser = webdriver.Chrome()

browser.get("https://www.google.com")

assert 'google' in browser.title.lower()

elem = browser.find_element(By.NAME, 'q')

elem.send_keys('openAI' + Keys.RETURN)

time.sleep(20)

browser.quit()
