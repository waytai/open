#########################################################################
#-*- coding:utf-8 -*-
# File Name: hello_flask.py
#########################################################################
#!/bin/python
from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello World!'

if __name__ == '__main__':
    app.run()
