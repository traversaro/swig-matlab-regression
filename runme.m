% file: runme.m

% Create parent object
a = refToInternalObject.A();

% Get reference to the internal object
b1 = a.getB();
b2 = a.getB();

% b1 and b2 are references to the same object
disp(sprintf('b1: %f', b1.getValue()))
disp(sprintf('b2: %f', b2.getValue()))

disp('Setting b1 to 100')
b1.setValue(100)

disp(sprintf('b1: %f', b1.getValue()))
disp(sprintf('b2: %f', b2.getValue()))
disp(sprintf('a.b: %f', a.getB().getValue()))

disp(sprintf('b1: %f', b1.getValue()))
disp(sprintf('b2: %f', b2.getValue()))
disp(sprintf('a.b: %f', a.getB().getValue()))
