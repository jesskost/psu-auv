# Interface implemented by State classes
class ICurrentState(object):
    def __init__(self):
        pass

    def execute(self):
        raise Exception("NotImplementedException")


class AUVStateContext:
    state = ICurrentState()
    current_state = state

    # start by executing the Initial state
    def __init__(self):
        context = AUVStateContext()
        initial = Initial()
        context.set_state(initial)
        context.auv_execute()

    # Change the current state to execute
    def set_state(self, state):
        self.current_state = state

    # Context calls the execute method of the object of type ICurrentState
    def auv_execute(self):
        self.current_state.execute()


class Initial(ICurrentState):
    switch_mode = "OFF"

    def __init__(self):
        pass

    def execute(self):
        if self.switch_mode == "OFF":
            #  Execute necessary code
            print("Hardware components reset.")
        else:
            # Execute code to start thrusters
            print("Power on thrusters")
            context = AUVStateContext()
            dive = Dive()
            context.set_state(dive)
            context.auv_execute()


class Dive(ICurrentState):
    barometric_pressure = 0
    altitude = 0
    REQUIRED_ALTITUDE = 150  # update value as necessary

    def __init__(self):
        pass

    def execute(self):
        while self.altitude > self.REQUIRED_ALTITUDE:
            self.barometric_pressure = 0
            # Update barometricPressure with value from barometer
            self.altitude = 0
            # Update altitude = barometricPressure converted to altitude using
            # correct scientific formula
            if self.altitude > self.REQUIRED_ALTITUDE:
                # Thruster full power
                print("Moving down!")

                # update altitude value. This is only a test value
                self.altitude = self.altitude - 20

        context = AUVStateContext()
        search = Search()
        context.set_state(search)
        context.auv_execute()


class Search(ICurrentState):
    object_found = False

    def __init__(self):
        pass

    def execute(self):
        # Activate object detection unit
        # Set objectFound = whether object(gate) detected/not

        while self.object_found == False:
            print("Searching for gate")
            object_in_current_frame = True

            if object_in_current_frame:
                self.object_found = True
                context = AUVStateContext()
                forward = Forward()
                context.set_state(forward)
                context.auv_execute()
            else:
                context = AUVStateContext()
                turn = Turn()
                context.set_state(turn)
                context.auv_execute()


class Forward(ICurrentState):
    distance = 0

    def __init__(self):
        pass

    def set_distance(self, value):
        self.distance = value

    def execute(self):
        # Move forward until required distance reached
        for position in range(self.distance):
            # Power thrusters forward
            print("Moving Forward!")


class Turn(ICurrentState):
    degrees = 0

    def __init__(self):
        pass

    def set_degrees(self, value):
        self.degrees = value

    def execute(self):
        print("Turning AUV!")
        if 0 <= self.degrees < 180:
            # Turn thrusters to the left
            print("Turning left")
        else:
            # Turn thrusters to the right
            print("Turning right")

        context = AUVStateContext()
        # Depending on which stage the AUV is currently in, go back to SEARCH or DECIDE
        # search = Search()
        # context.set_state(search)
        # OR
        # decide = Decide()
        # context.set_state(decide)
        context.auv_execute()


class Decide(ICurrentState):
    object_of_choice = "Chosen gate object"
    object_found = False

    def __init__(self):
        pass

    def set_obj_of_choice(self, obj):
        self.object_of_choice = obj

    def execute(self):
        # Activate object detection functionality
        while self.object_found == False:
            # Determine if objectOfChoice in current frame
            in_current_frame = True
            if in_current_frame:
                self.object_found = True
                context = AUVStateContext()
                forward = Forward()
                context.set_state(forward)
                context.auv_execute()
            else:
                context = AUVStateContext()
                turn = Turn()
                context.set_state(turn)
                context.auv_execute()


class Next(ICurrentState):
    def __init__(self):
        pass

    def execute(self):
        # Enter the next phase of the competition
        # after going through the gate
        context = AUVStateContext()
        forward = Forward()
        context.set_state(forward)
        context.auv_execute()

