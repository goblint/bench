obj = "    __goblint_check(r == 3); // NOWARN//SKIP "
res = obj =~ /(\b|\/)(TODO|SKIP)/
puts res
