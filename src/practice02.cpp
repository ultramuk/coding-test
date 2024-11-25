/* 연습 문제 2: 빠르고 범용적인 데이터 저장 컨테이너 만들기 */

#include <array>
#include <iostream>
#include <type_traits>

// 컨테이너를 생성하는 build_array() 함수 (빠른 원소 순회를 보장하는 std::array 반환)
// std::array에 저장할 원소의 타입을 결정하기 위해 std::common_type 템플릿 사용
// 함수 인자에 의존적이기 때문에 함수 반환형을 후행 리턴 타입으로 지정
template<typename ... Args>
auto build_array(Args&&... args) -> std::array<typename std::common_type
<Args...>::type, sizeof...(args)>
{
    using commonType = typename std::common_type<Args...>::type;
    return {std::forward<commonType>((Args&&)args)...};
}

int main()
{
    auto data = build_array(1, 0u, 'a', 3.2f, false);
    auto data2 = build_array(1, "Packet", 2.0);

    for (auto i: data)
        std::cout << i << " ";      // 함수에 전달된 인자들이 모두 float 자료형으로 변환

    // for (auto i: data2)
    //     std::cout << i << " ";   // 모든 데이터 타입을 하나의 공통 타입으로 변환할 수 없어서 에러가 발생

    std::cout << std::endl;
}
