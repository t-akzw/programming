from bs4 import BeautifulSoup
import re

IN_PATTERN = '入力例'
OUT_PATTERN = '出力例'

with open('atcoder.html', encoding='utf-8') as f:
    html = f.read()
# html = "<body><h1>python入門</h1><p>pythonの基礎について学習します</p></body>"

soup = BeautifulSoup(html, "html.parser")
tmp = soup.find('span', class_='lang-ja').find_all('div', class_='part')

in_cnt = 1
out_cnt = 1

def filewrite(output_path, data):
    with open(output_path, 'w') as f:
        print(data, file=f, end='')

for i in tmp:
    h3 = i.find('h3')
    is_input_example = re.match(IN_PATTERN, h3.text) != None
    is_output_example = re.match(OUT_PATTERN, h3.text) != None
    if is_input_example:
        data = i.find('pre').text
        path = 'input_example_'+str(in_cnt)+'.txt'
        filewrite(path, data)
        in_cnt += 1
    elif is_output_example:
        data = i.find('pre').text
        path = 'output_example_'+str(out_cnt)+'.txt'
        filewrite(path, data)
        out_cnt += 1