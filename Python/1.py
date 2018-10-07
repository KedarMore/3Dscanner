#scanned data
for i in range(90):
    for j in range(90):
        a[i,j]=input()
    pass
pass

#mesh
for i in range(90):
    for j in range(90):

        l=1

        mesh[k, l] = point(a[i % 90, j % 90], i, j, x)#first point
        l += 1
        mesh[k, l] = point(a[i % 90, j % 90], i, j, y)
        l += 1
        mesh[k, l] = point(a[i % 90, j % 90], i, j, z)
        l += 1

        mesh[k, l] = point(a[(i+1) % 90, j % 90], (i+1), j, x)  # second point
        l += 1
        mesh[k, l] = point(a[(i+1) % 90, j % 90], (i+1), j, y)
        l += 1
        mesh[k, l] = point(a[(i+1) % 90, j % 90], (i+1), j, z)
        l += 1

        mesh[k, l] = point(a[i % 90, (j+1) % 90], i, (j+1), x)  # third point
        l += 1
        mesh[k, l] = point(a[i % 90, (j+1) % 90], i, (j+1), y)
        l += 1
        mesh[k, l] = point(a[i % 90, (j+1) % 90], i, (j+1), z)

        k+=1

        l = 1

        mesh[k, l] = point(a[(i+1) % 90, (j+1) % 90], (i+1), (j+1), x)  # first point
        l += 1
        mesh[k, l] = point(a[(i+1) % 90, (j+1) % 90], (i+1), (j+1), y)
        l += 1
        mesh[k, l] = point(a[(i+1) % 90, (j+1) % 90], (i+1), (j+1), z)
        l += 1

        mesh[k, l] = point(a[(i+1) % 90, j % 90], (i+1), j, x)  # second point
        l += 1
        mesh[k, l] = point(a[(i+1) % 90, j % 90], (i+1), j, y)
        l += 1
        mesh[k, l] = point(a[(i+1) % 90, j % 90], (i+1), j, z)
        l += 1

        mesh[k, l] = point(a[i % 90, (j+1) % 90], i, (j+1), x)  # third point
        l += 1
        mesh[k, l] = point(a[i % 90, (j+1) % 90], i, (j+1), y)
        l += 1
        mesh[k, l] = point(a[i % 90, (j+1) % 90], i, (j+1), z)

    pass
pass

    def point(sensorValue,theta,phi,coOrdinate)
        if coOrdinate == x:
            x = sensorValue * math.sin(theta) * math.cos(phi)
            print x
            return x
        pass
        if coOrdinate == y:
            y = sensorValue * math.sin(theta) * math.sin(phi)
            print y
            return y
        pass
        if coOrdinate == z:
            z = sensorValue * math.cos(theta)
            print z
            return z
        pass
    return
