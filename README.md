# WINApi
Winapi
Основой поток создает другой поток, передавая ему параметр. Параметр может принимать два
значения: 0 или 1. Если параметр равен 0, то поток организует задержку в 10 мс и завершает свое
выполнение. Если параметр равен 1, то второй поток создает третий поток, который содержит
единственную ассемблерную операцию NOP. Измерить время исполнения второго потока в обоих
случаях. Измерения повторить 10 раз.