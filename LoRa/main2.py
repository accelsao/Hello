import webbrowser
import time

if __name__ == '__main__':
    url = 'https://www.youtube.com/watch?v=AGigc2U-Bxg'


    # Windows
    chrome_path = 'C:\Program Files (x86)\Google\Chrome\Application\chrome.exe'

    webbrowser.register('chrome', None, webbrowser.BackgroundBrowser(chrome_path))
    webbrowser.get('chrome').open_new_tab(url)

    url = 'https://www.youtube.com/watch?v=Yf7xffg_qi4'
    time.sleep(5)
    webbrowser.get('chrome').open(url)