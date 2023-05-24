#mge2zx Jenna Tuohy

def gellish2 (age):
    HRmax = 191.5-(0.007*(age**2))
    return HRmax

def in_target_range (hr,age):
    HR = (float(gellish2(age)) * 0.65) <= hr <= (float(gellish2(age))* 0.85)
    return HR







