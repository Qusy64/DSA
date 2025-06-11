import time

for i in range(1, 11):
    input_file = f"day{i}.txt"
    output_file = f"day{i}.out"

    try:
        with open(input_file, "r") as f:
            n = int(f.readline().strip())  
            a = []
            for line in f:
                a.extend(map(int, line.strip().split()))  

        start_time = time.time()

        a.sort()

        end_time = time.time()
        with open(output_file, "w", encoding="utf-8") as f:
            for x in a:
                f.write(str(x) + " ")
        with open("Time.txt", "a", encoding="utf-8") as f:
            f.write(f"Python sort() chạy: {end_time - start_time:.5f} giây ở dãy {i}\n")

        print(f"Đã xử lý xong {input_file}, kết quả lưu vào {output_file}")

    except Exception as e:
        print(f"Lỗi khi xử lý {input_file}: {e}")
