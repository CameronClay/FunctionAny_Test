#ifndef TYPE_LIST_DETAIL_SO_H
#define TYPE_LIST_DETAIL_SO_H

#include "TypeList_Detail.h"

namespace t_list
{
	template <typename... Ts> struct type_list;

	namespace detail
	{
		template <typename... Ts>
		using type_list = t_list::type_list<Ts...>;

		// Helper struct used for cartesian product
		template <typename T1, typename T2> 
		struct pair
		{
			using first  = T1;
			using second = T2;
		};

		// type_list_filter_binary - Adds all types in TList1 to a new type_list if Predicate<T, TList2>::value == true
		template <template <typename, typename> class Predicate, typename TList1, typename TList2> struct filter_binary;
		template <template <typename, typename> class Predicate, template <typename...> class TList1, template <typename...> class TList2, class... TList1Ts, class... TList2Ts>
		struct filter_binary<Predicate, TList1<TList1Ts...>, TList2<TList2Ts...>>
		{
			static_assert(all_templates_of_v<type_list, TList1<>, TList2<>>, "Error: filter_binary expected TList1 and TList2 to to be of type t_list::type_list<Ts...>");
			using type = type_list<>;
		};
		template <template <typename, typename> class Predicate, template <typename...> class TList1, template <typename...> class TList2, typename First, class... TList2Ts>
		struct filter_binary<Predicate, TList1<First>, TList2<TList2Ts...>>
		{
			using type = std::conditional_t<Predicate<First, TList2<TList2Ts...>>::value, type_list<First>, type_list<>>;
		};
		template <template <typename, typename> class Predicate, template <typename...> class TList1, template <typename...> class TList2, typename First, class... TList1Ts, class... TList2Ts>
		class filter_binary<Predicate, TList1<First, TList1Ts...>, TList2<TList2Ts...>>
		{
			using list_2   = TList2<TList2Ts...>;
			using helper_t = typename filter_binary<Predicate, TList1<TList1Ts...>, list_2>::type;
		public:
			using type     = typename helper_t::template append_front_unique_conditional_binary<Predicate, First, list_2>;
		};
		template <template <typename, typename> class Predicate, template <typename...> class TList1, template <typename...> class TList2,
			typename First, typename Second,
			class... TList1Ts, class... TList2Ts>
		class filter_binary<Predicate, TList1<First, Second, TList1Ts...>, TList2<TList2Ts...>>
		{
			using list_2   = TList2<TList2Ts...>;
			using helper_t = typename filter_binary<Predicate, TList1<TList1Ts...>, list_2>::type;
		public:
			using type = typename helper_t::
				template append_front_unique_conditional_binary<Predicate, Second, list_2> ::
				template append_front_unique_conditional_binary<Predicate, First,  list_2>;
		};
		template <template <typename, typename> class Predicate, template <typename...> class TList1, template <typename...> class TList2,
			typename First, typename Second, typename Third,
			class... TList1Ts, class... TList2Ts>
		class filter_binary<Predicate, TList1<First, Second, Third, TList1Ts...>, TList2<TList2Ts...>>
		{
			using list_2   = TList2<TList2Ts...>;
			using helper_t = typename filter_binary<Predicate, TList1<TList1Ts...>, list_2>::type;
		public:
			using type = typename helper_t::
				template append_front_unique_conditional_binary<Predicate, Third,  list_2> ::
				template append_front_unique_conditional_binary<Predicate, Second, list_2> ::
				template append_front_unique_conditional_binary<Predicate, First,  list_2>;
		};
		template <template <typename, typename> class Predicate, template <typename...> class TList1, template <typename...> class TList2,
			typename First, typename Second, typename Third, typename Fourth,
			class... TList1Ts, class... TList2Ts>
		class filter_binary<Predicate, TList1<First, Second, Third, Fourth, TList1Ts...>, TList2<TList2Ts...>>
		{
			using list_2   = TList2<TList2Ts...>;
			using helper_t = typename filter_binary<Predicate, TList1<TList1Ts...>, list_2>::type;
		public:
			using type = typename helper_t::
				template append_front_unique_conditional_binary<Predicate, Fourth, list_2> ::				
				template append_front_unique_conditional_binary<Predicate, Third,  list_2> ::
				template append_front_unique_conditional_binary<Predicate, Second, list_2> ::
				template append_front_unique_conditional_binary<Predicate, First,  list_2>;
		};
		template <template <typename, typename> class Predicate, template <typename...> class TList1, template <typename...> class TList2,
			typename First, typename Second, typename Third, typename Fourth, typename Fifth,
			class... TList1Ts, class... TList2Ts>
		class filter_binary<Predicate, TList1<First, Second, Third, Fourth, Fifth, TList1Ts...>, TList2<TList2Ts...>>
		{
			using list_2   = TList2<TList2Ts...>;
			using helper_t = typename filter_binary<Predicate, TList1<TList1Ts...>, list_2>::type;
		public:
			using type = typename helper_t::
				template append_front_unique_conditional_binary<Predicate, Fifth,  list_2> ::
				template append_front_unique_conditional_binary<Predicate, Fourth, list_2> ::
				template append_front_unique_conditional_binary<Predicate, Third,  list_2> ::
				template append_front_unique_conditional_binary<Predicate, Second, list_2> ::
				template append_front_unique_conditional_binary<Predicate, First,  list_2>;
		};
		template <template <typename, typename> class Predicate, template <typename...> class TList1, template <typename...> class TList2, 
			      typename First, typename Second, typename Third, typename Fourth, typename Fifth,
			      typename Sixth, typename Seventh, typename Eighth, typename Nineth, typename Tenth,
			      class... TList1Ts, class... TList2Ts>
		class filter_binary<Predicate, TList1<First, Second, Third, Fourth, Fifth, Sixth, Seventh, Eighth, Nineth, Tenth, TList1Ts...>, TList2<TList2Ts...>>
		{
			using list_2   = TList2<TList2Ts...>;
			using helper_t = typename filter_binary<Predicate, TList1<TList1Ts...>, list_2>::type;
		public:
			using type = typename helper_t::
				template append_front_unique_conditional_binary<Predicate, Tenth,   list_2> ::
				template append_front_unique_conditional_binary<Predicate, Nineth,  list_2> ::
				template append_front_unique_conditional_binary<Predicate, Eighth,  list_2> ::
				template append_front_unique_conditional_binary<Predicate, Seventh, list_2> ::
				template append_front_unique_conditional_binary<Predicate, Sixth,   list_2> ::
				template append_front_unique_conditional_binary<Predicate, Fifth,   list_2> ::
				template append_front_unique_conditional_binary<Predicate, Fourth,  list_2> ::
				template append_front_unique_conditional_binary<Predicate, Third,   list_2> ::
				template append_front_unique_conditional_binary<Predicate, Second,  list_2> ::
				template append_front_unique_conditional_binary<Predicate, First,   list_2>;
		};
		template <template <typename, typename> class Predicate, typename TList1, typename TList2>
		using filter_binary_t = typename filter_binary<Predicate, TList1, TList2>::type;

		template<typename T, typename TList> struct predicate_intersection;
		template<typename T, template <typename...> class TList, typename... Ts>
		struct predicate_intersection<T, TList<Ts...>>
		{
			static constexpr bool value = contains_v<T, Ts...>;
		};
		template<typename T, typename TList> struct predicate_difference;
		template<typename T, template <typename...> class TList, typename... Ts>
		struct predicate_difference<T, TList<Ts...>>
		{
			static constexpr bool value = !contains_v<T, Ts...>;
		};

		template<typename TList1, typename TList2>
		using union_helper           = typename TList1::template append_lists<TList2>;

		// union_t - type_list containing all types in either TList1 and TList2
		template<typename TList1, typename TList2>
		using union_t                = typename union_helper<TList1, TList2>::unique;
		// intersection_t - type_list containing all types in both TList1 and TList2
		template<typename TList1, typename TList2>
		using intersection_t         = filter_binary_t<predicate_intersection, TList1, TList2>;
		// predicate_difference_t - type_list containing all types in both TList1 that are not in TList2
		template<typename TList1, typename TList2>
		using difference_t           = filter_binary_t<predicate_difference,   TList1, TList2>;
		// symmetric_difference_t - type_list containing all types in both TList1 and TList2 but not in the intersection
		template<typename TList1, typename TList2, typename... TListRest>
		using symmetric_difference_t = typename difference_t<TList1, TList2>::template setop_union<difference_t<TList2, TList1>>;

		// cartesian_product - Cross Product of two type_lists
		//		type = pair<T, U>...;
		template <typename TList1, typename TList2> struct cartesian_product;
		template <template <typename...> class TList1, template <typename...> class TList2, typename... Us>
		struct cartesian_product<TList1<>, TList2<Us...>>
		{
			using type = type_list<>;
		};
		template <template <typename...> class TList1, template <typename...> class TList2, typename... Ts>
		struct cartesian_product<TList1<Ts...>, TList2<>>
		{
			using type = type_list<>;
		};
		template <template <typename...> class TList1, template <typename...> class TList2, typename First, typename... Ts, typename... Us>
		struct cartesian_product<TList1<First, Ts...>, TList2<Us...>>
		{
			using type = append_t<typename cartesian_product<TList1<Ts...>, TList2<Us...>>::type, pair<First, Us>...>;
		};
		template <template <typename...> class TList1, template <typename...> class TList2, 
			typename First, typename Second, 
			typename... Ts, typename... Us>
		struct cartesian_product<TList1<First, Second, Ts...>, 
			                     TList2<Us...>>
		{
			using type = append_t<typename cartesian_product<TList1<Ts...>, TList2<Us...>>::type,
				pair<First, Us>..., pair<Second, Us>...>;
		};
		template <template <typename...> class TList1, template <typename...> class TList2, 
			typename First, typename Second, typename Third,
			typename... Ts, typename... Us>
		struct cartesian_product<TList1<First, Second, Third, Ts...>,
			                     TList2<Us...>>
		{
			using type = append_t<typename cartesian_product<TList1<Ts...>, TList2<Us...>>::type,
				pair<First, Us>..., pair<Second, Us>..., pair<Third, Us>...>;
		};
		template <template <typename...> class TList1, template <typename...> class TList2,
			typename First, typename Second, typename Third, typename Fourth,
			typename... Ts, typename... Us>
		struct cartesian_product<TList1<First, Second, Third, Fourth, Ts...>,
			TList2<Us...>>
		{
			using type = append_t<typename cartesian_product<TList1<Ts...>, TList2<Us...>>::type,
				pair<First, Us>..., pair<Second, Us>..., pair<Third, Us>..., pair<Fourth, Us>...>;
		};
		template <template <typename...> class TList1, template <typename...> class TList2,
			typename First, typename Second, typename Third, typename Fourth, typename Fifth,
			typename... Ts, typename... Us>
		struct cartesian_product<TList1<First, Second, Third, Fourth, Fifth, Ts...>,
			TList2<Us...>>
		{
			using type = append_t<typename cartesian_product<TList1<Ts...>, TList2<Us...>>::type,
				pair<First, Us>..., pair<Second, Us>..., pair<Third, Us>..., pair<Fourth, Us>..., pair<Fifth, Us>...>;
		};
		template <template <typename...> class TList1, template <typename...> class TList2,
			typename First, typename Second, typename Third, typename Fourth, typename Fifth,
			typename Sixth, typename Seventh, typename Eighth, typename Nineth, typename Tenth,
			typename... Ts, typename... Us>
		struct cartesian_product<TList1<First, Second, Third, Fourth, Fifth, Sixth, Seventh, Eighth, Nineth, Tenth, Ts...>,
			TList2<Us...>>
		{
			using type = append_t<typename cartesian_product<TList1<Ts...>, TList2<Us...>>::type,
				pair<First, Us>..., pair<Second,  Us>..., pair<Third,  Us>..., pair<Fourth, Us>..., pair<Fifth, Us>...,
				pair<Sixth, Us>..., pair<Seventh, Us>..., pair<Eighth, Us>..., pair<Nineth, Us>..., pair<Tenth, Us>...>;
		};
		template <typename TList1, typename TList2>
		using cartesian_product_t = typename cartesian_product<TList1, TList2>::type;
	}
}

#endif