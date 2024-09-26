class MyCalendar {
public:
    vector<pair<int, int>> bookings;  // To store the intervals
    
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        // Check if the new event conflicts with any existing event
        for (const auto& booking : bookings) {
            int booked_start = booking.first;
            int booked_end = booking.second;
            // Check if there is any overlap
            if (max(booked_start, start) < min(booked_end, end)) {
                return false;
            }
        }
        // If no conflicts, add the event
        bookings.push_back({start, end});
        return true;
    }
};
