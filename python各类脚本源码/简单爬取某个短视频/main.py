import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC


def wait(locator, timeout=10):
    # '''等到元素加载完成'''
    WebDriverWait(driver, timeout).until(EC.presence_of_element_located(locator))


driver = webdriver.Chrome()
driver.get('https://www.kuaishou.com/short-video/3xvx5ayqd9bqbv2?authorId=3xdds3wwvtm6ung&streamSource=brilliant&area=brilliantxxcarefully')

locator = (By.CLASS_NAME, 'title')  # 相当于find_elements_by_class_name
wait(locator)
elements = driver.find_elements_by_class_name('title')
link = []
linkNum = len(elements)
for i in range(linkNum):
    wait(locator)
    elements = driver.find_elements_by_class_name('title')  # 再次获取元素，预防StaleElementReferenceException
    driver.execute_script('arguments[0].click();', elements[i])  # 模拟用户点击
    time.sleep(0.01)
    print(i, driver.current_url)
    link.append(driver.current_url)
    time.sleep(0.01)  # 留时间给页面后退，网不好调大点，此处用driver.implicitly_wait()无效
    driver.back()

driver.quit()
print('共{}条链接'.format(len(link)))
