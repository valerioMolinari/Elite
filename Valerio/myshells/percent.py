import sys

argv = sys.argv

if len(argv[1:]) != 2:
    raise Exception(f"Two parameters attended (value and total) but {len(argv)} recevied")

try:
    value, total = map(lambda x: int(x), argv[1:3])
except ValueError:
    raise Exception(f"\n\tvalue and total must be integers")

print("%.2f%%" % ((value * 100) / total))
