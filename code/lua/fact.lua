function factorial(n)
  local x = 1
  for i = 2,n do
    x = x * i
  end
  return x
end

print("factorial(5)="..factorial(5));