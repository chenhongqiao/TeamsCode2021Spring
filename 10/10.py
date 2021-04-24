current_time = input()
S, D = map(int, input().split())

cur_mins = int(current_time[:2]) * 60 + int(current_time[3:])
final_mins = cur_mins + int(60*D/S)

print("{:02d}:{:02d}".format(int(final_mins/60) % 24, final_mins % 60))
