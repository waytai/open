source myenv/bin/activate
#uvicorn main:app --reload
uvicorn main:app --host 127.0.0.1 --port 8000
