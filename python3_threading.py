import threading

def execute(number):
    print(threading.currentThread().getName(), number)

if __name__ == '__main__':
    for i in range(1, 9):
        my_thread = threading.Thread(target=execute, args=(i,))
        my_thread.start()

