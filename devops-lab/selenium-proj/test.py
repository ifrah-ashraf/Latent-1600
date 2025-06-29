import unittest 
from selenium import webdriver

class TestSelenium(unittest.TestCase):
    def setUp(self):
        self.browser = webdriver.Chrome()
        self.addCleanup(self.browser.quit)

    def test_page_title(self):
        self.browser.get('https://www.google.com')
        self.assertIn('Google', self.browser.title)

if __name__ == "__main__":
    unittest.main()