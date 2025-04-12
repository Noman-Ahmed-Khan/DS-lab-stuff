import currencyapicom



client = currencyapicom.Client('cur_live_VSWJyndJL2fYsXbxYk2E8i3WKDYLtHq7nmLR0yKc')
result = client.latest('USD',currencies=['PKR'])
print(result['data']['PKR']['value'])