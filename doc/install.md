# Install xtensor for linux

Follow the install guide for *xtensor* available here : https://github.com/xtensor-stack/xtensor

Go to user directory : `~`

*xtensor* dependency is *[xtl](https://github.com/xtensor-stack/xtl)* : https://github.com/xtensor-stack/xtensor#dependencies

Install *xtl*:

```
git clone https://github.com/xtensor-stack/xtl.git
cd xtl
cmake -D CMAKE_INSTALL_PREFIX=/usr
sudo make install
```

Install *xtensor* :
```
git clone https://github.com/xtensor-stack/xtensor.git
cd xtensor
cmake -D CMAKE_INSTALL_PREFIX=/usr
sudo make install
```

CLion will detect the library after building the project.