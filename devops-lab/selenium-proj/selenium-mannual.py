from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
import time 

chrome_drive_path="/usr/local/bin/chromedriver"
service = Service(executable_path=chrome_drive_path)
driver=webdriver.Chrome(service=service)

driver.get("https://www.google.com")
assert "google" in driver.title.lower()

elem = driver.find_element(By.NAME, 'q')

elem.send_keys('openAI' + Keys.RETURN)

time.sleep(10)

driver.quit()
