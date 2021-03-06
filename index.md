# Using TinyML and Ardunio to alert when your name is called on a conference call


## Project Summary

If you've been working from home during the COVID-19 pandemic, I'm sure you've experienced "[Zoom Fatigue](https://www.nationalgeographic.com/science/2020/04/coronavirus-zoom-fatigue-is-taxing-the-brain-here-is-why-that-happens/)". I was joking with a few friends recently that so many people zone out or multi-task during long zoom calls, and then don’t hear and/or panic when their name is called. I joked that I could build an AI device that could listen for your name to be spoken and then alert you. 

In a few hours I got this working!

<div align="center">
<iframe height="500" align="center" src="https://www.youtube.com/embed/MzTY79iMFFQ" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe></div>

<br>

In my reading about TinyML, I came across [Edge Impulse](https://www.edgeimpulse.com/) which has incredible software that allows even beginners to create embedded AI models. Edge Impulse offers an _almost_ no-code platform (you'll need to be comfortable working with a command line, and knowledge of C++ is helpful to work with the Arduino interface) to collecting data, building/validating a model, and deploying the model to a microcontroller. I loosely followed [this tutorial](https://docs.edgeimpulse.com/docs/responding-to-your-voice) from Edge Impulse. 

**_Obvious disclaimer for my employer: This was just a project for a laugh that I have no intention of actually using in real life, and I did not use any real meetings for training or validation_**.

## What is TinyML/Embedded AI and why did I use it?

There are some simple ways you could do this by streaming the data to the internet, like [Google's Speech-to-Text API](https://cloud.google.com/speech-to-text), but this is not a secure solution since all of your meeting content would be sent to remote servers and while I'm not questioning Google's security here, there are obvious privacy concerns.

With recent advances AI libraries designed for small edge devices like [TensorFlow Lite](https://www.tensorflow.org/lite), it is possible to build and deploy an AI/ML model "[at the edge](https://www.theverge.com/circuitbreaker/2018/5/7/17327584/edge-computing-cloud-google-microsoft-apple-amazon)" on a small microcontroller wihtout network connectivity. If the device can listen to speech and make classifications remotely with no onboard storage or network connectivity, then we can be assured that there are no privacy or security concerns about having a device listen in on our communications. I bought an [Arduino Nano BLE Sense](https://store.arduino.cc/usa/nano-33-ble-sense) a few months back to learn more about embedded AI in microcontrollers, but hadn't found a great use case besides [having some fun](https://create.arduino.cc/projecthub/user1382012/magic-wand-29fa3b) with the built-in accelerometer. The Nano BLE Sense only has 1MB of storage and no network connectivity, so we can be assured that there is no hidden way it is storing audio or streaming to the internet (_note: it does have bluetooth low energy capability but I am not using it here and let's ignore for now since this project is just for fun_).

## Model Building and Deployment

### 1. Collect Data

To build a model which will recognize my name, I needed two classes of data (in this case, audio clips): someone saying the word Brandon, and literally any other type of noise. To collect samples of the word "Brandon", I kept recording audio clips of me saying my name in different tones. I got my wife to record a few as well, but to build a better model I'd ideally want recordings as many different people as possible. 

To collect data which is "not Brandon", ideally I'd want to record a bunch of meeting audio when people aren't saying Brandon. Obviously I wasn't going to use real meetings, but thankfully there are plenty of existing audio datasets out there for building ML models. I considered for a second just recording a bunch of audio from The Office, but I ended up using background noise from the [The Microsoft Scalable Noisy Speech Dataset (MS-SNSD)](https://github.com/microsoft/MS-SNSD). 

I then had to turn the raw audio into a simplified format which the model can understand. I will admit I have no experience in audio processing, but relying on the advice from Edge Impulse I used their [MFCC](https://en.wikipedia.org/wiki/Mel-frequency_cepstrum) processing functionality.

### 2. Train and Test Model

There are any number of types of classifiers I could use here, but from previous reading on audio processing I wanted to try a [neural network](https://en.wikipedia.org/wiki/Neural_network). Edge Impulse uses the [Keras](https://keras.io/) library, which I've used directly in python before, but the GUI makes it really simple to create a model if you don't have prior experiene with Python. For this short post I won't go too in-depth with a discussion of the model since my goal was just a fun proof of concept, not an in-depth exploration of using neural networks for audio classification.

I didn't spend too much time perfecting the model, but a simple neural network with two 1D Conv layers yielded pretty great results right out of the box (with 20% held for test data):

![Model Results](https://lh3.googleusercontent.com/pw/ACtC-3f62m90kO67z-eSLPjYldDlPLqV2UvI_HgjVphEEXGOzpwvWOpegLJJmSohIrDUXwDRWB_zYlZp3FLF7ze2sF8BSVZX2j4k0TrjPtLdufCdM72p8lyIDNdKPELXJzdhnfUAuBLXo7E50cszkQ1_z_PsoQ=w2226-h958-no)

In theory I would have spent much more time testing and perfecting this model, but again, I was much more focused on the Arduino aspect of the project than the model building. 

### 3. Deploy Model

We need to turn the model into a format which can run on the Arduino, which would either be compiled binary or Arduino code (essentially, C++). Both Edge Impulse and TensorFlow Lite have several options for this step. I exported my model from Edge Impulse directly to Arduino code which I then modified to tinker with a simple LED circuit. Edge Impulse created the C++ and header files needed to run the classifier, so I just needed to write some simple logic to flash an LED when the model detected that "Brandon" was heard. I made any changes to the code in the file [src/recognize_brandon.cpp](https://github.com/brandonfcohen1/name-alert/blob/master/src/recognize_brandon.cpp) in the repo. Everything else, including the bulk of that file was generated by Edge Impulse!

In the `loop()` function on the Arduino, the audio sensor is constantly running samples through the model and calculating the "probability" that the word "Brandon" has been heard. If this happens, a function will be triggered to output a pulse out of a given pin to flash an LED for 1 second. I flashed my recognize_brandon program to the Arduino board, disconnected from USB and ran on AAA batteries (to prove that the model wasn't interacting with my laptop or the internet through USB). 

I wired pin 13 on the Arduino board to flash an LED with a 220&#8486; resistor:

<div align="center">
<img src="https://lh3.googleusercontent.com/pw/ACtC-3eT-Za5hTkJAyJy_fr9ofvx10VjzJcfKUnzGjGrWc1pWkp1eT63igqbRzIEaWIwrSuIoZGtl6OAkX0JbSHLpTmexLHSkohCD93DXB4tqcwnocXdyyI5Dtm2w86TQWQTLd5pqDWxzTnUGRt7fn4L1UBNuQ=w1198-h1596-no" align="center" width="400" ></div>

Check out another video of the device in action:
<div align="center">
<iframe height="560" align="center" src="https://www.youtube.com/embed/qb80EbZbcvQ" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe></div>
<br>
<br>

## Further work

As I said, this was only just for fun and to create a basic example. A proper implementation of this concept would require considerably more training data and model tuning. Of course, simply flashing a light when your name is called might not even be that useful, since by the time your name is called, it's already too late if you're not paying attention! Maybe what I actually need to build is a model that can _predict_ when your name will come up... 

### Interested in learning more?

Get in touch over email at [brandon.f.cohen@gmail.com](mailto:brandon.f.cohen@gmail.com). Check out some of my other projects at [https://www.brandonfcohen.com](https://www.brandonfcohen.com).
