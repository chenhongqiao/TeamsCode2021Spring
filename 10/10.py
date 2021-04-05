current_time = input()
S, D = map(int, input().split())

cur_hour, cur_mins = int(current_time[:2]), int(current_time[3:])
hour, mins = D//S, int((D/S - D//S) * 60)

final_m = cur_mins + mins

if final_m >= 60:
    hour += 1
    final_m -= 60

final_h = (cur_hour + hour) % 24

print("{}:{}".format(final_h, final_m))


