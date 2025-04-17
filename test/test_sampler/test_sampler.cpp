#include <Arduino.h>
#include <unity.h>
#include "Sampler.h"

void test_analyzeSample_safe_values() {
    TEST_ASSERT_FALSE(analyzeSample(2.0, 1.5));  // Within range
}

void test_analyzeSample_unsafe_ph_low() {
    TEST_ASSERT_TRUE(analyzeSample(1.0, 1.5));  // Low pH
}

void test_analyzeSample_unsafe_ph_high() {
    TEST_ASSERT_TRUE(analyzeSample(3.0, 1.5));  // High pH
}

void test_analyzeSample_unsafe_turbidity() {
    TEST_ASSERT_TRUE(analyzeSample(2.0, 3.0));  // High turbidity
}

void setup() {
    // Runs once before tests
    UNITY_BEGIN();

    RUN_TEST(test_analyzeSample_safe_values);
    RUN_TEST(test_analyzeSample_unsafe_ph_low);
    RUN_TEST(test_analyzeSample_unsafe_ph_high);
    RUN_TEST(test_analyzeSample_unsafe_turbidity);

    UNITY_END();
}

void loop() {
    // Nothing needed here
}
